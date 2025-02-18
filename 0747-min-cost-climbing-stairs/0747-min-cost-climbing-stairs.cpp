class Solution {
public:
    int n;
    int solve(vector<int>& dp, vector<int>& cost, int idx) {
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];

        int take = cost[idx] + solve(dp, cost, idx + 1);
        int ntake = cost[idx] + solve(dp, cost, idx + 2);

        return dp[idx] = min(take, ntake);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(solve(dp, cost, 0), solve(dp, cost, 1));  // Start from either 0 or 1
    }
};
