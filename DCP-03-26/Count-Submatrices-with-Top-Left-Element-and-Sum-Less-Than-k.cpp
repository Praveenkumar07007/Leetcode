1class Solution {
2public:
3    int countSubmatrices(vector<vector<int>>& grid, int k) {
4        int n = grid.size();
5        int m = grid[0].size();
6
7        // Build prefix sum for first column
8        for(int i = 1; i < n; i++) 
9            grid[i][0] += grid[i-1][0];
10
11        // Build prefix sum for first row
12        for(int j = 1; j < m; j++) 
13            grid[0][j] += grid[0][j-1];
14
15        // Build full 2D prefix sum
16        for(int i = 1; i < n; i++) {
17            for(int j = 1; j < m; j++) {
18                grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
19            }
20        }
21
22        // Count valid submatrices
23        int cnt = 0;
24        for(int i = 0; i < n; i++) {
25            for(int j = 0; j < m; j++) {
26                if(grid[i][j] <= k) cnt++;
27            }
28        }
29
30        return cnt;
31    }
32};