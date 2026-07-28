#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> row = {0, +1, 0, -1};
    vector<int> col = {+1, 0, -1, 0};
    void dfs(vector<vector<bool>> &vis, vector<vector<char>>& grid, int i, int j, int n, int m){
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int ni = i + row[k];
            int nj = j + col[k];
            if(ni >=0 && nj >=0 && ni < n && nj <m && grid[i][j] == '1' && (!vis[ni][nj])){
                dfs(vis, grid, ni, nj, n, m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((!vis[i][j]) && grid[i][j] == '1'){
                    cnt++;
                    dfs(vis, grid, i, j, n, m);
                }
            }
        }
        return cnt;
    }
};

