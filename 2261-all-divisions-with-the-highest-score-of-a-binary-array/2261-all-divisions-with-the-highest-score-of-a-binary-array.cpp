class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = 0, countZeros = 0, countOnes = 0, maxScore = 0;
        vector<int> result;
        for (int num : nums) {
            if (num == 1) totalOnes++;
        }

        for (int i = 0; i <= n; i++) {
            int score = countZeros + (totalOnes - countOnes);
            if (score > maxScore) {
                maxScore = score;
                result.clear();
                result.push_back(i);
            } else if (score == maxScore) {
                result.push_back(i);
            }
            if (i < n) {
                if (nums[i] == 0) countZeros++;
                else countOnes++;
            }
        }

        return result;
    }
};
