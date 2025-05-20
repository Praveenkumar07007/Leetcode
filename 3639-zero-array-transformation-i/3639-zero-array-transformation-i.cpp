class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queris) {
        vector<int> q(nums.size() + 1, 0);
        for (auto& que : queris) {
            q[que[0]]++;
            q[que[1] + 1]--;
        }
        for (int i = 1; i < nums.size(); i++) {
            q[i] += q[i - 1];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (q[i] < nums[i])
                return false;
        }
        return true;
    }
};