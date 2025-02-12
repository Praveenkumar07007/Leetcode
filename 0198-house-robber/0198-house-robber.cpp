class Solution {
public:
    // top down approach 

    // int solve(vector<int>&dp,vector<int>&nums,int i,int n){
    //     if(i>=n) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int steal = nums[i]+solve(dp,nums,i+2,n);
    //     int skip = solve(dp,nums,i+1,n);
    //     return dp[i]= max(steal,skip);
    // }
    // int rob(vector<int>& nums) {
    //     int n= nums.size();
    //     vector<int> dp(n+1,-1);
    //     return solve(dp,nums,0,n);
    // }

    // bottom up approach
    //dp[i] = max stolen money till  i house 
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n ==1 ) return nums[0];
        vector<int> dp(n+1,-1);
        dp[0] = 0; // no house no money
        dp[1] = nums[0]; 
        for(int i=2;i<=n;i++){
            int steal = nums[i-1]+dp[i-2];
            int skip = dp[i-1];
            dp[i]= max(steal,skip);
        }
        return dp[n];
    }
};