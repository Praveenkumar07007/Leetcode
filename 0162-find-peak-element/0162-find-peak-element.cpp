class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1]) {
                high = mid; // Peak is on the left (including mid)
            } else {
                low = mid + 1; // Peak is on the right
            }
        }
        return low; // or high — both point to a peak
    }
};
