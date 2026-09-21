#include <bits/stdc++.h>
using namespace std;

class SolutionDFS
{
public:
    void dfs(vector<int> &vis, vector<vector<int>> &adj, int node, stack<int> &st)
    {
        vis[node] = 1;

        for (int adjNode : adj[node])
        {
            if (!vis[adjNode])
            {
                dfs(vis, adj, adjNode, st);
            }
        }

        st.push(node);
    }

    vector<int> topo_sort(int V, vector<vector<int>> &adj)
    {
        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(vis, adj, i, st);
        }

        vector<int> topo;

        while (!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }

        return topo;
    }
};

int main()
{
    SolutionDFS obj;

    int V = 6;
    vector<vector<int>> adj(V);

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> ans = obj.topo_sort(V, adj);

    cout << "Topological Order: ";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}