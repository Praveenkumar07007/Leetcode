class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        // Edge case: if the starting or ending cell is an obstacle
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) {
            return 0;
        }

        // Create a DP table
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Initialize the starting cell
        dp[0][0] = 1;

        // Fill the DP table
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0; // Obstacle cell
                } else {
                    if (i > 0) dp[i][j] += dp[i-1][j]; // Paths from top
                    if (j > 0) dp[i][j] += dp[i][j-1]; // Paths from left
                }
            }
        }

        // Return the result in the bottom-right corner
        return dp[n-1][m-1];
    }
};
