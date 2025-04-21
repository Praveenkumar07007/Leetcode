class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) 
    {
        long long minSum = 0, maxSum = 0, current = 0;

        for (int diff : differences) {
            current += diff;
            minSum = min(minSum, current);
            maxSum = max(maxSum, current);
        }

        long long minStart = lower - minSum;
        long long maxStart = upper - maxSum;

        return max(0LL, maxStart - minStart + 1);
        
    }
};