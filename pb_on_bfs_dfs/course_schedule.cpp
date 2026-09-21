#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int node, int parent, vector<int> adj[], int vis[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                if (dfs(it, node, adj, vis) == true)
                    return true;
                else if (it != parent)
                    return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {

        int vis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                return dfs(i, -1, adj, vis);
        }
        return false;
    }
};

int main()
{
    Solution cycle;

    // Test Case 1 (No Cycle)
    {
        int V = 5;
        vector<int> adj[V];

        adj[0].push_back(1);
        adj[1].push_back(0);

        adj[1].push_back(2);
        adj[2].push_back(1);

        adj[2].push_back(3);
        adj[3].push_back(2);

        adj[3].push_back(4);
        adj[4].push_back(3);

        cout << "Cycle Test 1: "
             << cycle.isCycle(V, adj) << endl;
    }

    // Test Case 2 (Triangle Cycle)
    {
        int V = 3;
        vector<int> adj[V];

        adj[0].push_back(1);
        adj[1].push_back(0);

        adj[1].push_back(2);
        adj[2].push_back(1);

        adj[2].push_back(0);
        adj[0].push_back(2);

        cout << "Cycle Test 2: "
             << cycle.isCycle(V, adj) << endl;
    }

    // Test Case 3
    {
        int V = 6;
        vector<int> adj[V];

        adj[0].push_back(1);
        adj[1].push_back(0);

        adj[1].push_back(2);
        adj[2].push_back(1);

        adj[2].push_back(3);
        adj[3].push_back(2);

        adj[3].push_back(4);
        adj[4].push_back(3);

        adj[4].push_back(1);
        adj[1].push_back(4);

        cout << "Cycle Test 3: "
             << cycle.isCycle(V, adj) << endl;
    }

    return 0;
}