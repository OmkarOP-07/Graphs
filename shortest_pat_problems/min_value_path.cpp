#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));


        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, 0}});

        dist[0][0] = 0;
        vector<int> rrow = {1, 0, -1, 0};
        vector<int> rcol = {0, -1, 0, 1};

        while (!pq.empty())
        {
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int distance = pq.top().first;
            pq.pop();

            for(int i = 0; i < 4; i++){
                int ncol = col + rcol[i];
                int nrow = row + rrow[i];
                if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n){
                    int diff = abs(heights[row][col] - heights[nrow][ncol]);
                    int ndist = max(distance, diff);
                    if(dist[nrow][ncol] > ndist){
                        dist[nrow][ncol] = ndist;
                        pq.push({ndist, {nrow,ncol}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};

int main()
{

    Solution sol;

    // Test Case 1
    vector<vector<int>> heights1 = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}};

    cout << "Test Case 1: "
         << sol.minimumEffortPath(heights1)
         << endl;

    // Test Case 2
    vector<vector<int>> heights2 = {
        {1, 2, 3},
        {3, 8, 4},
        {5, 3, 5}};

    cout << "Test Case 2: "
         << sol.minimumEffortPath(heights2)
         << endl;

    // Test Case 3
    vector<vector<int>> heights3 = {
        {1, 2, 1, 1, 1},
        {1, 2, 1, 2, 1},
        {1, 2, 1, 2, 1},
        {1, 2, 1, 2, 1},
        {1, 1, 1, 2, 1}};

    cout << "Test Case 3: "
         << sol.minimumEffortPath(heights3)
         << endl;

    // Test Case 4 - Single cell
    vector<vector<int>> heights4 = {
        {5}};

    cout << "Test Case 4: "
         << sol.minimumEffortPath(heights4)
         << endl;

    // Test Case 5 - Single row
    vector<vector<int>> heights5 = {
        {1, 10, 6, 7, 9, 10}};

    cout << "Test Case 5: "
         << sol.minimumEffortPath(heights5)
         << endl;

    // Test Case 6 - Single column
    vector<vector<int>> heights6 = {
        {1},
        {5},
        {2},
        {8}};

    cout << "Test Case 6: "
         << sol.minimumEffortPath(heights6)
         << endl;

    return 0;
}