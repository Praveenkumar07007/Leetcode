class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> arr;
        int n = nums.size();
        int i=0;
        while(i<n){
            int correctIdx = nums[i] -1;
            if(nums[correctIdx]==nums[i] || correctIdx == i) i++;
            else swap(nums[i],nums[correctIdx]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                arr.push_back(i+1);
            }
        }
        return arr;
    }
};