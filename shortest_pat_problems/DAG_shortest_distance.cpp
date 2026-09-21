#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<int> &vis, vector<pair<int, int>> adj[], int node, stack<int> &st)
    {
        vis[node] = 1;

        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode.first])
            {
                dfs(vis, adj, adjNode.first, st);
            }
        }

        st.push(node);
    }

    stack<int> topo_sort(int V, vector<pair<int, int>> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(vis, adj, i, st);
        }

        return st;
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[V];

        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }
        stack<int> st = topo_sort(V, adj);

        vector<int> vis(V, 0);
        vector<int> dist(V, -1);
        dist[0] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (auto it : adj[node])
            {
                int nnode = it.first;
                int distance = it.second;
                // cout<<nnode<<" "<<distance<<" "<<calD<<" ";
                if (dist[node] != -1)
                {
                    int calD = dist[node] + distance;

                    if (dist[nnode] == -1 || calD < dist[nnode])
                    {
                        dist[nnode] = calD;
                    }
                }
            }
        }
        return dist;
    }
};
int main()
{
    int V = 7;
    int E = 8;

    vector<vector<int>> edges = {
        {0, 1, 2},
        {1, 3, 1},
        {2, 3, 3},
        {4, 0, 3},
        {4, 2, 1},
        {5, 4, 1},
        {6, 4, 2},
        {6, 5, 3}};
    Solution obj;

    vector<int> ans = obj.shortestPath(V, E, edges);

    cout << "Shortest Distance from Source (6):\n";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}