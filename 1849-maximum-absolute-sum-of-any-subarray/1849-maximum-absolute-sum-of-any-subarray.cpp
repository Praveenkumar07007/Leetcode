class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0, ans = 0;
        int currentMax = 0, currentMin = 0;

        for (int num : nums) {
            currentMax = max(num, currentMax + num); 
            maxSum = max(maxSum, currentMax);
            currentMin = min(num, currentMin + num); 
            minSum = min(minSum, currentMin);
        }

        ans = max(abs(maxSum), abs(minSum));
        return ans;
    }
};