#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& A, int k) {
        sort(A.begin(), A.end()); // Array sort karo
        long long sum = 0; // Sum long long rakho kyunki bada number ho sakta hai
        int N = A.size(), ans = 0;
        for (int i = 0, j = 0; j < N; ++j) {
            sum += A[j]; // Window mein naya element add karo
            // Jab tak window invalid hai, left side se shrink karo
            while ((long long)(j - i + 1) * A[j] - sum > k) {
                sum -= A[i]; // Left element hatao
                i++;
            }
            ans = max(ans, j - i + 1); // Max frequency update karo
        }
        return ans;
    }
};