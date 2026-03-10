1class Solution {
2public:
3    int numberOfStableArrays(int zeros, int ones, int limit) {
4
5        const int MOD = 1e9 + 7;
6        vector<vector<vector<long long>>> dp(
7            zeros + 1,
8            vector<vector<long long>>(ones + 1, vector<long long>(2, 0))
9        );
10
11        dp[0][0][0] = 1;
12        dp[0][0][1] = 1;
13
14        for (int i = 0; i <= zeros; i++) {
15            for (int j = 0; j <= ones; j++) {
16
17                if (i == 0 && j == 0) continue;
18
19                long long endWithZero = 0;
20                long long endWithOne = 0;
21
22                if (j > 0) {
23                    endWithZero = dp[i][j-1][1];
24
25                    if (j > 1)
26                        endWithZero = (endWithZero + dp[i][j-1][0]) % MOD;
27
28                    if (j > limit)
29                        endWithZero = (endWithZero - dp[i][j-1-limit][1] + MOD) % MOD;
30                }
31
32                if (i > 0) {
33                    endWithOne = dp[i-1][j][0];
34
35                    if (i > 1)
36                        endWithOne = (endWithOne + dp[i-1][j][1]) % MOD;
37
38                    if (i > limit)
39                        endWithOne = (endWithOne - dp[i-1-limit][j][0] + MOD) % MOD;
40                }
41
42                dp[i][j][0] = endWithZero % MOD;
43                dp[i][j][1] = endWithOne % MOD;
44            }
45        }
46
47        return (dp[zeros][ones][0] + dp[zeros][ones][1]) % MOD;
48    }
49};