class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;  // because product can't be less than 1 if k <= 1

        int prod = 1, res = 0;
        int i = 0;
        int n = nums.size();

        for (int j = 0; j < n; ++j) {
            prod *= nums[j];

            while (prod >= k && i <= j) {
                prod /= nums[i];
                i++;
            }

            res += (j - i + 1);
        }

        return res;
    }
};
