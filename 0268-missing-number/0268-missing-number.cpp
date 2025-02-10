class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // using extra space ----------------------------
        // int n = nums.size();
        // vector<bool> check(n+1,false);
        // for(int i=0;i<n;i++){
        //     int ele = nums[i];
        //     check[ele] = true;
        // }
        // for(int i=0;i<=n;i++){
        //     if(check[i]==false) return i;
        // }
        // return 100;

        // without using extra space ---------------------------
        int n = nums.size();
        int i=0;
        while(i<n){
            int correctIndex = nums[i];
            if(i==correctIndex || nums[i]==n) i++;
            else swap(nums[i],nums[correctIndex]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i) return i;
        }
        return n;
    }
};