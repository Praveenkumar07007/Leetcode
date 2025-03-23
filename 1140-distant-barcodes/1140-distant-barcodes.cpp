class Solution {
public:
    typedef pair<int, int> P;

    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> count;
        for (int code : barcodes) {
            count[code]++;
        }

        priority_queue<P> pq;
        for (auto &[num, freq] : count) {
            pq.push({freq, num});
        }

        vector<int> result;
        while (pq.size() >= 2) {
            auto P1 = pq.top(); pq.pop();
            auto P2 = pq.top(); pq.pop();

            result.push_back(P1.second);
            result.push_back(P2.second);

            if (--P1.first > 0) pq.push(P1);
            if (--P2.first > 0) pq.push(P2);
        }

        if (!pq.empty()) {
            result.push_back(pq.top().second);
        }

        return result;
    }
};
