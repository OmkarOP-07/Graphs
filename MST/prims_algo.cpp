#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        int sum = 0;
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<vector<pair<int, int>>> adj(V);

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // For undirected graph
        }
        //   weight, node
        pq.push({0, 0});
        vector<int> vis(V, 0);

        while (!pq.empty())
        {
            auto it = pq.top();
            int node = it.second;
            int cost = it.first;
            pq.pop();

            if (vis[node] == 1)
                continue;
            vis[node] = 1;
            sum = sum + cost;

            for (auto adjNode : adj[node])
            {
                int ewt = adjNode.second;
                int anode = adjNode.first;
                if (vis[anode] == 0)
                {
                    pq.push({ewt, anode});
                }
            }
        }
        return sum;
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