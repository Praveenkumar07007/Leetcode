class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<int> res(n, 1);

        for(int i = 1; i <= k; i++) {
            for(int j = 1; j < n; j++) {
                res[j] = (res[j - 1] + res[j]) % MOD;
            }
        }

        return res[n - 1];
    }
};
