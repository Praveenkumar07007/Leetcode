class Solution {
public:
    // top down approach
    // int solve(int n,vector<int>&dp){
    //     if(n<=2) return n;
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n] = solve(n-1,dp)+solve(n-2,dp);
    // }
    // int climbStairs(int n){
    //     vector<int> dp(n+1,-1);
    //     return solve(n,dp);
    // }


    // bottomup approach 

    // int climbStairs(int n) {
    //     if(n==1) return 1;
    //     if(n==2) return 2;
    //     vector<int>dp(n+1,-1);
    //     dp[1]=1;
    //     dp[2]=2;
    //     for(int i=3;i<=n;i++){
    //         dp[i] = dp[i-1]+dp[i-2];
    //     }
    //     return dp[n];
    // }

//  constant space solution

    int climbStairs(int n){
        if(n<=2) return n;
        int a = 1;
        int b = 2;
        int c = 0;
        for(int i=3;i<n+1;i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }

};