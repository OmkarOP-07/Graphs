#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1)
            return -1;

        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        
        queue<pair<int, pair<int,int>>> q;
    
        q.push({0, {0,0}});

        dist[0][0] = 0; 

        while (!q.empty())
        {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int distance = q.front().first;

            q.pop();
            vector<int> dcol = {1, 0, -1, 0, 1, -1, -1, 1};
            vector<int> drow = {0, 1, 0, -1, 1, -1, 1, -1};

            for (int i = 0; i < 4; i++)
            {
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                int ndist  = distance + 1;
                if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && ndist < dist[nrow][ncol] && (!grid[nrow][ncol] == 0)){
                    q.push({ndist,{nrow, ncol}});
                    dist[nrow][ncol] = ndist;
                }
                if(ncol == n-1 && nrow == m-1){
                    return dist[n-1][m-1];
                }
            }
            
        }
        return -1;
    }
};


int main() {
    Solution solution;
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
    int result = solution.shortestPathBinaryMatrix(grid);
    cout << "Shortest path length: " << result << endl;
    return 0;
}