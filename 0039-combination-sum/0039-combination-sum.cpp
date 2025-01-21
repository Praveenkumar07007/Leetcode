class Solution {
public:
    void findCombination(vector<int>& arr, int target, int idx, vector<vector<int>>& finalans, vector<int>& temp) {
        if (idx == arr.size()) {
            if (target == 0) {
                finalans.push_back(temp); 
            }
            return;
        }
        if (arr[idx] <= target) {
            temp.push_back(arr[idx]);
            findCombination(arr, target - arr[idx], idx, finalans, temp);
            temp.pop_back(); 
        }
        findCombination(arr, target, idx + 1, finalans, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> finalans;
        vector<int> temp;
        findCombination(candidates, target, 0, finalans, temp);
        return finalans; 
    }
};
