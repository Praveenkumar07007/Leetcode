class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == nums[mid ^ 1]) {
                // Pair is correct, move right
                low = mid + 1;
            } else {
                // Pair is broken, move left
                high = mid - 1;
            }
        }

        return nums[low]; // low will point to the single element
    }
};
