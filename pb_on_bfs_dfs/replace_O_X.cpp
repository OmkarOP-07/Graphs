#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, int m, int n)
    {
        vis[row][col] = 1;
        vector<int> rvect = {+1, 0, -1, 0};
        vector<int> cvect = {0, +1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + rvect[i];
            int ncol = col + cvect[i];
            if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && (!vis[nrow][ncol]) && board[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, vis, board, m, n);
                vis[nrow][ncol] = 1;
                board[nrow][ncol] = 'O';
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();    // rows
        int n = board[0].size(); // columns
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<char>> ans(m, vector<char>(n));

        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
            {
                dfs(0, i, vis, board, m, n);
                ans[0][i] = 'O';
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (board[m - 1][i] == 'O')
            {
                dfs(m - 1, i, vis, board, m, n);
                ans[m - 1][i] = 'O';
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(i, 0, vis,board, m, n);
                ans[i][0] = 'O';
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (board[i][n - 1] == 'O')
            {
                dfs(i, n - 1, vis, board, m, n);
                ans[i][n - 1] = 'O';
            }
        }   
        for (int i = 0; i < m; i++)
        {
            for (int  j = 0; j < n; j++)
            {
                if(!vis[i][j])
                board[i][j] = 'X';
            }
            
        }
        
       
    }
};

#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<char>> &board)
{
    for (auto &row : board)
    {
        for (char ch : row)
            cout << ch << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    Solution obj;

    // Test Case 1 (LeetCode Example)
    vector<vector<char>> board1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};

    obj.solve(board1);

    cout << "Test Case 1:\n";
    printBoard(board1);

    // Test Case 2 (No changes)
    vector<vector<char>> board2 = {
        {'O', 'O'},
        {'O', 'O'}};

    obj.solve(board2);

    cout << "Test Case 2:\n";
    printBoard(board2);

    // Test Case 3
    vector<vector<char>> board3 = {
        {'X', 'O', 'X', 'X'},
        {'O', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'O'}};

    obj.solve(board3);

    cout << "Test Case 3:\n";
    printBoard(board3);

    return 0;
}