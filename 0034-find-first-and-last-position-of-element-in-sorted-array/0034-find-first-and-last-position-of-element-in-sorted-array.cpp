class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1}; 
        
        int lo = 0, hi = n - 1;
        int l = -1, h = -1; 
        //bs for left bound
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                h = mid; 
                hi = mid - 1; 
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (h == -1) return {-1, -1}; 

        l = h; 
        lo = h, hi = n - 1; 

        // Binary search for the right bound
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                h = mid; 
                lo = mid + 1; 
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return {l, h};
    }
};
