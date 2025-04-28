class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> mp;
        for (string& word : words) {
            mp[word]++;
        }
        auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>,
                       decltype(cmp)>
            pq(cmp);
        for (const auto& pair : mp) {
            pq.push({pair.second, pair.first});
        }

        while (k-- && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
