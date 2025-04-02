class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int totalEven = 0, totalOdd = 0;
        int leftEven = 0, leftOdd = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) totalEven += nums[i];
            else totalOdd += nums[i];
        }

        // Iterate to check balance after removing each index
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                totalEven -= nums[i]; // Remove current even index
            } else {
                totalOdd -= nums[i]; // Remove current odd index
            }

            // New even and odd sums after removal
            if (leftOdd + totalEven == leftEven + totalOdd) {
                ans++;
            }

            // Update prefix sums for next iteration
            if (i % 2 == 0) {
                leftEven += nums[i];
            } else {
                leftOdd += nums[i];
            }
        }

        return ans;
    }
};
