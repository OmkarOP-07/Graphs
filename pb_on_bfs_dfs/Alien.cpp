#include <bits/stdc++.h>
using namespace std;

class Solution
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

    string findOrder(string dictionary[], int K, int N)
    {
        vector<vector<int>> adj(K);

        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dictionary[i];
            string s2 = dictionary[i + 1];

            int len = min(s1.size(), s2.size());

            for (int ptr = 0; ptr < len; ptr++)
            {
                if (s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topo_sort(K, adj);

        string ans = "";

        for (int x : topo)
            ans += char(x + 'a');

        return ans;
    }
};

int main()
{
    Solution obj;

    // Test Case 1
    string dict1[] = {"baa", "abcd", "abca", "cab", "cad"};
    int N1 = 5;
    int K1 = 4;

    cout << "Test Case 1: "
         << obj.findOrder(dict1, K1, N1) << endl;

    // Test Case 2
    string dict2[] = {"caa", "aaa", "aab"};
    int N2 = 3;
    int K2 = 3;

    cout << "Test Case 2: "
         << obj.findOrder(dict2, K2, N2) << endl;

    // Test Case 3
    string dict3[] = {"abc", "abd", "bcd"};
    int N3 = 3;
    int K3 = 4;

    cout << "Test Case 3: "
         << obj.findOrder(dict3, K3, N3) << endl;

    return 0;
}