#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> dist(n + 1, 1e9);

        // convert edge list to adjacency list
        for (auto it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});
        dist[k] = 0;
        while (!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;

                if (edgeWeight + dis < dist[adjNode]) {
                    dist[adjNode] = edgeWeight + dis;
                    pq.push({edgeWeight + dis, adjNode});
                }
            }
        }
        int maxi = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9)
                return -1;

            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};
