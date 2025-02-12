class Solution {
public:
    // top down approach

    // int solve(int n,vector<int>&dp){
    //     if(n==0) return 0;
    //     if(n==1) return 1;
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n] = solve(n-1,dp)+solve(n-2,dp);
    // }
    // int fib(int n) {
    //     vector<int> dp(n+1,-1);
    //     return solve(n,dp);
    // }

    //Bottom up Approach

    // int fib(int n){
    //     if(n<=1) return n;
    //     vector<int> dp(n+1,-1);

    //     dp[0] = 0;
    //     dp[1] = 1;
    //     for(int i=2;i<=n;i++){
    //         dp[i] = dp[i-1]+dp[i-2];
    //     }
    //     return dp[n];

    // }

    // in constant space complexity

    int fib(int n){
        if(n<2) return n;
        int a=0,b=1,c;
        for(int i=1;i<n;i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }

};