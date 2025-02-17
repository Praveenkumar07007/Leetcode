class Solution {
public:
    int n;
    vector<vector<int>> dp;
    
    int solve(int idx, int prev, vector<vector<int>>& pairs) {
        if (idx >= n) return 0;

        if (dp[idx][prev + 1] != -1) return dp[idx][prev + 1];

        // Option 1: Skip the current pair
        int skip = solve(idx + 1, prev, pairs);

        // Option 2: Take the current pair (only if it's valid)
        int take = 0;
        if (prev == -1 || pairs[prev][1] < pairs[idx][0]) {
            take = 1 + solve(idx + 1, idx, pairs);
        }

        return dp[idx][prev + 1] = max(skip, take);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];  // Sort by the second element
        });

        dp = vector<vector<int>>(n, vector<int>(n + 1, -1));
        return solve(0, -1, pairs);
    }
};
