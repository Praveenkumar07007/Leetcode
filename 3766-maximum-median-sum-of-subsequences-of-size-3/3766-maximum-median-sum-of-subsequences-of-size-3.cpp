class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;  // less than one group

        sort(nums.begin(), nums.end());
        long long ans = 0;

        // Start from the second last triplet element and move back by 2 steps each time
        for(int i = n - 2; i >= n/3; i -= 2) {
            ans += nums[i];
        }
        return ans;
    }
};
