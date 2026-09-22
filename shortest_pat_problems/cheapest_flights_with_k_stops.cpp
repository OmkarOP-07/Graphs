#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int,int>> adj[n];
        
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[0] = 0;
        while(!q.empty()){
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            q.pop();

            if(stops>k) continue;
            for(auto iter : adj[node]){
                int adjNode = iter.first;
                int edW = iter.second;

                if(cost + edW < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost + edW;
                    q.push({stops+1, {adjNode, cost + edW}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    vector<vector<int>> flights1 = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };

    cout << "Test Case 1: "
         << sol.findCheapestPrice(3, flights1, 0, 2, 1)
         << endl;


    // Test Case 2
    vector<vector<int>> flights2 = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };

    cout << "Test Case 2: "
         << sol.findCheapestPrice(3, flights2, 0, 2, 0)
         << endl;


    // Test Case 3
    vector<vector<int>> flights3 = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 3, 500},
        {1, 3, 250}
    };

    cout << "Test Case 3: "
         << sol.findCheapestPrice(4, flights3, 0, 3, 1)
         << endl;

    return 0;
}