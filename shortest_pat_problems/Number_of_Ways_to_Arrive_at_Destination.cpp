#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int V, vector<vector<int>> &roads)
    {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> adj(V);

        vector<long long> dist(V, 1e18);
        vector<int> ways(V, 0);

        for (auto it : roads)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>>
            pq;

        pq.push({0, 0});

        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty())
        {
            long long dis = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edgeWeight = it.second;

                long long newDist = dis + edgeWeight;

                if (newDist < dist[adjNode])
                {
                    dist[adjNode] = newDist;

                    ways[adjNode] = ways[node];

                    pq.push({newDist, adjNode});
                }
                else if (newDist == dist[adjNode])
                {
                    ways[adjNode] =
                        (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[V - 1];
    }
};

int main()
{
}

//  vector<int> dijkstra(int V, vector<vector<int>> &roads, int src)
//     {
//         vector<vector<pair<int, int>>> adj(V);
//         vector<int> dist(V, 1e9);

//         // convert edge list to adjacency list
//         for (auto it : roads)
//         {
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];

//             adj[u].push_back({v, wt});
//             adj[v].push_back({u, wt}); // remove this for directed graph
//         }
//         priority_queue<pair<int, int>,
//                        vector<pair<int, int>>,
//                        greater<pair<int, int>>>
//             pq;
//         pq.push({0, src});
//         dist[src] = 0;
//         while (!pq.empty())
//         {
//             int node = pq.top().second;
//             int dis = pq.top().first;
//             pq.pop();
//             for(auto it : adj[node]){
//                 int adjNode = it.first;
//                 int edgeWeight = it.second;

//                 if(edgeWeight + dis < dist[adjNode]){
//                     dist[adjNode] = edgeWeight + dis;
//                     pq.push({edgeWeight + dis, adjNode});
//                 }
//             }
//         }
//         return dist;
//     }