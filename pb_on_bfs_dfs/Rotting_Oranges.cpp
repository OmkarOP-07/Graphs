#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }

        int ans = 0;
        vector<int> drow = {1, 0, -1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        while (!q.empty())
        {
            int rrow = q.front().first.first;
            int rcol = q.front().first.second;
            int t = q.front().second;
            ans = max(ans, t);
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = rrow + drow[i];
                int ncol = rcol + dcol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 &&
                    grid[nrow][ncol] == 1)
                {
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] != 2)
                {
                    return -1;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};

    int ans = sol.orangesRotting(grid);

    cout << "Minimum time to rot all oranges: " << ans << endl;

    return 0;
}