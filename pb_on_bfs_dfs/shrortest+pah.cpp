#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortst_path(vector<vector<int>> &mat, int V, int src, int dest)
    {
        queue<pair<int, int>> q;
        vector<int> distanceV(V + 1, INT_MAX);
        q.push({src, 0});
        distanceV[src] = 0;
        while (!q.empty())
        {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            for (auto it : mat[node])
            {
                int ndist = dist + 1;
                if (ndist < distanceV[it])
                {
                    distanceV[it] = ndist;
                    q.push({it, ndist});
                }
                
            }
        }

        return distanceV[dest];
    }
};

int main()
{
    Solution cycle;

    // Test Case 1 (No Cycle)
    {
        int V = 5;
        vector<vector<int>> adj(V);

        adj[0].push_back(1);
        adj[1].push_back(0);

        adj[1].push_back(2);
        adj[2].push_back(1);

        adj[2].push_back(3);
        adj[3].push_back(2);

        adj[3].push_back(4);
        adj[4].push_back(3);

        Solution sh;

        cout << "Shortest path is : "
             << sh.shortst_path(adj, V, 0, 3) << endl;
    }
}