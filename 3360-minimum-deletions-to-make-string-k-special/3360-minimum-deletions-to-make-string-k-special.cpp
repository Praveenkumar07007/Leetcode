class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> mp;
        for (char ch : word) {
            mp[ch]++;
        }

        vector<int> freq;
        for (auto &p : mp) {
            freq.push_back(p.second);
        }

        int res = INT_MAX;
        sort(freq.begin(), freq.end());  

        for (int target : freq) {
            int deletions = 0;
            for (int f : freq) {
                if (f > target + k) {
                    deletions += f - (target + k);
                } else if (f < target) {
                    deletions += f;
                }
            }
            res = min(res, deletions);
        }

        return res;
    }
};
