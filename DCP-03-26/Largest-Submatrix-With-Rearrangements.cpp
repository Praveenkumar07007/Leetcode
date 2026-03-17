1class Solution {
2public:
3    int largestSubmatrix(vector<vector<int>>& grid) {
4        int rows = grid.size();
5        int cols = grid[0].size();
6        int maxArea = 0;
7
8        for (int r = 0; r < rows; r++) {
9
10            // Build height histogram
11            for (int c = 0; c < cols; c++) {
12                if (grid[r][c] == 1 && r > 0) {
13                    grid[r][c] += grid[r - 1][c];
14                }
15            }
16
17            // Copy and sort heights
18            vector<int> heights = grid[r];
19            sort(heights.begin(), heights.end());
20
21            // Compute area
22            for (int i = cols - 1; i >= 0; i--) {
23                int width = cols - i;
24                int area = heights[i] * width;
25                maxArea = max(maxArea, area);
26            }
27        }
28
29        return maxArea;
30    }
31};