class Solution {
public:
    vector<vector<int>> buildpascal(int n){
        vector<vector<int>> dp(n); // local DP
        for(int i = 0; i < n; i++){
            dp[i].resize(i + 1);       // each row size = i + 1
            dp[i][0] = dp[i][i] = 1;   // first and last element = 1
            for(int j = 1; j < i; j++){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; // pascal relation
            }
        }
        return dp;
    }

    vector<vector<int>> generate(int numRows) {
        return buildpascal(numRows);
    }
};
