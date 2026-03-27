1class Solution {
2public:
3    vector<int> getBiggestThree(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        set<int> sums;
8
9        for (int i = 0; i < m; i++) {
10            for (int j = 0; j < n; j++) {
11
12                // area 0 rhombus
13                sums.insert(grid[i][j]);
14
15                int maxRadius = min({i, j, m - 1 - i, n - 1 - j});
16
17                for (int k = 1; k <= maxRadius; k++) {
18                    int sum = 0;
19
20                    int x = i - k, y = j;
21
22                    // top -> right
23                    for (int d = 0; d < k; d++) {
24                        sum += grid[x + d][y + d];
25                    }
26
27                    // right -> bottom
28                    for (int d = 0; d < k; d++) {
29                        sum += grid[i + d][j + k - d];
30                    }
31
32                    // bottom -> left
33                    for (int d = 0; d < k; d++) {
34                        sum += grid[i + k - d][j - d];
35                    }
36
37                    // left -> top
38                    for (int d = 0; d < k; d++) {
39                        sum += grid[i - d][j - k + d];
40                    }
41
42                    sums.insert(sum);
43                }
44            }
45        }
46
47        vector<int> ans;
48        for (auto it = sums.rbegin(); it != sums.rend() && ans.size() < 3;
49             it++) {
50            ans.push_back(*it);
51        }
52
53        return ans;
54    }
55};