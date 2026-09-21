#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        vector<vector<pair<int, int>>> adj(V);
        vector<int> dist(V, 1e9);

        // convert edge list to adjacency list
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // remove this for directed graph
        }
        set<pair<int, int>> st;
        st.insert({0, src});
        dist[src] = 0;
        while (!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
             
            for(auto it : adj[node]){ 
                int adjNode = it.first;
                int edgeWeight = it.second;

                if(edgeWeight + dis < dist[adjNode]){
                    dist[adjNode] = edgeWeight + dis;
                    st.insert({edgeWeight + dis, adjNode});
                }
            }
        }
        return dist;
    }
};

int main()
{
    Solution obj;

    int V = 5;

    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 2, 1},
        {2, 1, 2},
        {1, 3, 1},
        {2, 3, 5},
        {3, 4, 3}
    };

    int src = 0;

    vector<int> ans = obj.dijkstra(V, edges, src);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}