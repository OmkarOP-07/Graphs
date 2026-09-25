#include <bits/stdc++.h>
using namespace std;


class DisjointSet {
private:
    vector<int> parent;
    vector<int> rankValue;

public:
    // Initializes one independent set for every node.
    DisjointSet(int n) {
        parent.resize(n + 1);
        rankValue.assign(n + 1, 0);

        // Make every node its own parent.
        for (int node = 1; node <= n; node++) {
            parent[node] = node;
        }
    }

    // Returns the representative using path compression.
    int findParent(int node) {
        // Base case: node is its own representative.
        if (parent[node] == node) {
            return node;
        }

        // Compress the path while finding the representative.
        parent[node] = findParent(parent[node]);

        return parent[node];
    }

    // Merges two sets using rank balancing.
    void unionByRank(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);

        // Same representative means both nodes are already connected.
        if (rootU == rootV) {
            return;
        }

        // Keep the higher-rank root as the parent.
        if (rankValue[rootU] < rankValue[rootV]) {
            swap(rootU, rootV);
        }

        // Attach the lower-rank root to the higher-rank root.
        parent[rootV] = rootU;

        // Increase rank only when both ranks are equal.
        if (rankValue[rootU] == rankValue[rootV]) {
            rankValue[rootU]++;
        }
    }

    // Checks whether two nodes share one set.
    bool find(int u, int v) {
        return findParent(u) == findParent(v);
    }
};

class Solution {
    public:
    int spanningTree(int V, vector<vector<int>> &edges){
        vector<vector<int>> adj = edges;
        for(int i = 0; i < edges.size(); i++){
            adj[i][0] = edges[i][2];
            adj[i][1] = edges[i][0];
            adj[i][2] = edges[i][1];
        }
        sort(adj.begin(), adj.end());
        DisjointSet ds(V);
        int mstWt = 0;
        for(auto it : adj){
            int w = it[0];
            int u = it[1];
            int v = it[2];

            if(ds.findParent(u) != ds.findParent(v)){
                mstWt += w;
                ds.unionByRank(u,v);    
            }
        }
        return mstWt;   
    }
};
// V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
int main()
{
    int V = 3;

    vector<vector<int>> edges = {
        {0, 1, 5},
        {1, 2, 3},
        {0, 2, 1}
    };

    Solution obj;

    cout << "MST Weight = "
         << obj.spanningTree(V, edges)<<endl;

    return 0;
}