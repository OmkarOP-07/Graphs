#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // Create adjacency list
        vector<vector<int>> adj(V);

        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(V, 0);

        // Check every connected component
        for (int start = 0; start < V; start++)
        {
            if (vis[start])
                continue;

            queue<pair<int, int>> q;
            q.push({start, -1});
            vis[start] = 1;

            while (!q.empty())
            {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for (int adjNode : adj[node])
                {
                    if (!vis[adjNode])
                    {
                        vis[adjNode] = 1;
                        q.push({adjNode, node});
                    }
                    else if (adjNode != parent)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
int main()
{
    // Test Case 1 : Graph with a cycle
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {2, 3}};

    int V1 = 4;
    int E1 = 4;

    cout << "Test Case 1 (Cycle): ";
    Solution sh;

    if (sh.isCycle(V1, edges))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    // Test Case 2 : Graph without a cycle
    vector<vector<int>> edges2 = {
        {0, 1},
        {1, 2},
        {2, 3}};

    int V2 = 4;
    int E2 = 3;

    cout << "Test Case 2 (No Cycle): ";
    if (sh.isCycle(V2, edges2))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}