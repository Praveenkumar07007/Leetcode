class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, N = s.size(), ans = 0, cnt[26] = {}, maxCnt = 0;
        for (; j < N; ++j) {
            maxCnt = max(maxCnt, ++cnt[s[j] - 'A']);
            while (j - i + 1 - maxCnt > k) cnt[s[i++] - 'A']--;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};