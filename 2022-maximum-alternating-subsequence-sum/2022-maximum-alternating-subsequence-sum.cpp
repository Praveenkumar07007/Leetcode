class Solution {
public:
    int n;
    vector<vector<long long>> dp;

    long long solve(int idx, vector<int>& nums, bool flag) {
        if (idx >= n) return 0;

        if (dp[idx][flag] != -1) return dp[idx][flag];

        // Skip current index
        long long skip = solve(idx + 1, nums, flag);

        // Take current index
        long long val = nums[idx];
        if (!flag) val = -val;
        long long take = val + solve(idx + 1, nums, !flag);

        return dp[idx][flag] = max(skip, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<long long>(2, -1));
        return solve(0, nums, true);
    }
};
