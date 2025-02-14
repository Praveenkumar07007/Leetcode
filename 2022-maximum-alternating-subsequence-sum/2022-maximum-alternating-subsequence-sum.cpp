class Solution {
public:
    // int n;

    // long long solve(int idx, vector<int>& nums, bool flag, vector<vector<long long>>& dp) {
    //     if (idx >= n) return 0;

    //     if (dp[idx][flag] != -1) return dp[idx][flag];

    //     // Skip current index
    //     long long skip = solve(idx + 1, nums, flag, dp);

    //     // Take current index
    //     long long val = nums[idx];
    //     if (!flag) val = -val;
    //     long long take = val + solve(idx + 1, nums, !flag, dp);

    //     return dp[idx][flag] = max(skip, take);
    // }

    // long long maxAlternatingSum(vector<int>& nums) {
    //     n = nums.size();
    //     vector<vector<long long>> dp(n, vector<long long>(2, -1));
    //     return solve(0, nums, true, dp); // intially we are at 0th index which is even that 's why we are passing true as even and false as odd
    // }


    long long maxAlternatingSum(vector<int>& nums) {
        long long evenSum = 0, oddSum = 0;

        for (int num : nums) {
            long long newEvenSum = max(evenSum, oddSum + num);
            long long newOddSum = max(oddSum, evenSum - num);
            evenSum = newEvenSum;
            oddSum = newOddSum;
        }

        return evenSum;
    }

};
