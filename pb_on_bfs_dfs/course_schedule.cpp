#include <bits/stdc++.h>
using namespace std;

class SolutionDFS
{
public:
    void dfs(vector<int> &vis, vector<vector<int>> &prerequisites, int i, stack<int> &st)
    {
        vis[i] = 1; 
        for (auto adjNode : prerequisites[i]){
            if (!vis[adjNode])
            {
                dfs(vis, prerequisites, adjNode, st);
                st.push(adjNode);
            }
        }
        st.push(i);
    }


    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> vis(numCourses, 0);
        stack<int> st;
        
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
                dfs(vis, prerequisites, i, st);
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

class SolutionBFS
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
    // ===========================
    // SolutionDFS Test Cases
    // ===========================

    SolutionDFS topo;

    // Test Case 1
    {
        int V = 4;
        vector<vector<int>> adj(V);

        adj[0].push_back(1);
        adj[0].push_back(2);
        adj[1].push_back(3);
        adj[2].push_back(3);

        cout << "DFS Topological Sort Test 1:\n";
        vector<int> ans = topo.findOrder(V, adj);

        for (int x : ans)
            cout << x << " ";
        cout << "\n\n";
    }

    // Test Case 2
    {
        int V = 6;
        vector<vector<int>> adj(V);

        adj[5].push_back(2);
        adj[5].push_back(0);
        adj[4].push_back(0);
        adj[4].push_back(1);
        adj[2].push_back(3);
        adj[3].push_back(1);

        cout << "DFS Topological Sort Test 2:\n";
        vector<int> ans = topo.findOrder(V, adj);

        for (int x : ans)
            cout << x << " ";
        cout << "\n\n";
    }

    // Test Case 3
    {
        int V = 5;
        vector<vector<int>> adj(V);

        adj[0].push_back(2);
        adj[1].push_back(2);
        adj[2].push_back(3);
        adj[3].push_back(4);

        cout << "DFS Topological Sort Test 3:\n";
        vector<int> ans = topo.findOrder(V, adj);

        for (int x : ans)
            cout << x << " ";
        cout << "\n\n";
    }

    // ===========================
    // SolutionBFS (Cycle Detection)
    // ===========================

    SolutionBFS cycle;

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