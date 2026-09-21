#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &vis, bool col)
    {
        int n = graph.size();
        int m = graph[node].size();
        vis[node] = col;
        for (int adjnode : graph[node])
        {
            if (vis[adjnode] == -1)
            {
                if (!dfs(adjnode, graph, vis, !col))
                    return false;
            }
            else if (vis[adjnode] == col)
            {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> vis(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++)
        {
            if (vis[i] == -1)
            {
                if (dfs(i, graph, vis, 0) == false)
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution obj;

    // Test Case 1: Bipartite
    vector<vector<int>> graph1 = {
        {1,3},
        {0,2},
        {1,3},
        {0,2}
    };

    cout << "Test Case 1: "
         << obj.isBipartite(graph1) << endl;   // Expected: 1


    // Test Case 2: Not Bipartite (Triangle)
    vector<vector<int>> graph2 = {
        {1,2},
        {0,2},
        {0,1}
    };

    cout << "Test Case 2: "
         << obj.isBipartite(graph2) << endl;   // Expected: 0


    // Test Case 3: LeetCode Example (Not Bipartite)
    vector<vector<int>> graph3 = {
        {1,2,3},
        {0,2},
        {0,1,3},
        {0,2}
    };

    cout << "Test Case 3: "
         << obj.isBipartite(graph3) << endl;   // Expected: 0


    // Test Case 4: Disconnected Graph (Bipartite)
    vector<vector<int>> graph4 = {
        {1},
        {0},
        {3},
        {2}
    };

    cout << "Test Case 4: "
         << obj.isBipartite(graph4) << endl;   // Expected: 1


    // Test Case 5: Single Node
    vector<vector<int>> graph5 = {
        {}
    };

    cout << "Test Case 5: "
         << obj.isBipartite(graph5) << endl;   // Expected: 1

    return 0;
}
