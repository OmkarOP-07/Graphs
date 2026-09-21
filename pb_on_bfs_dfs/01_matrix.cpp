#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        vector<int> ccol = {+1, 0, -1, 0};
        vector<int> rrow = {0, +1, 0, -1};
        while (!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            ans[x][y] = dist;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newX = x + ccol[i];
                int newY = y + rrow[i];
                if (newX >= 0 && newY >= 0 && newX < n && newY < m && (!vis[newX][newY]))
                {
                    vis[newX][newY] = 1;
                    q.push({{newX, newY}, dist + 1});
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;

    // Test Case 1
    vector<vector<int>> mat1 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}}; 
    vector<vector<int>> ans = obj.updateMatrix(mat1);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}