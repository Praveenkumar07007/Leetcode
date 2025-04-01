class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int counta = 0, countb = 0, minDeletions;

        // Count total 'a's in the string
        for (char c : s) {
            if (c == 'a') counta++;
        }

        // Initialize minDeletions with the worst-case scenario (removing all 'a's)
        minDeletions = counta;

        for (char c : s) {
            if (c == 'a') {
                counta--;  // Remove one 'a' from the left part
            } else {
                countb++;  // Count 'b' in the left part
            }
            minDeletions = min(minDeletions, counta + countb);
        }

        return minDeletions;
    }
};
