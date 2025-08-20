class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            dp[i][m-1] = matrix[i][m-1];
        }
        for(int j=0;j<m;j++){
            dp[n-1][j] = matrix[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(matrix[i][j] == 1){
                    dp[i][j] = 1 + min({dp[i+1][j+1], dp[i+1][j], dp[i][j+1]});
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum += dp[i][j];
            }
        }
        return sum;
    }
};