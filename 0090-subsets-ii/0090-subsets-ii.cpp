class Solution {
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int> temp, int idx) {
        if (idx == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        helper(nums, ans, temp, idx + 1);
        temp.pop_back();
        while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) {
            idx++;
        }
        helper(nums, ans, temp, idx + 1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums, ans, temp, 0);
        return ans;
    }
};
