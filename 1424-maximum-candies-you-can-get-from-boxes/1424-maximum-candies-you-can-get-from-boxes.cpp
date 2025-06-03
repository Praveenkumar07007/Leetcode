class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans = 0;

        queue<int> q;
        vector<bool> seen(status.size(), false);
        vector<bool> join(status.size(), false);
        vector<int> ckk;
        ckk.reserve(status.size());
        
        for (int i: initialBoxes) {
            seen[i] = true;
            if (status[i]) {
                q.push(i);
                
                join[i] = true;
                for (int ks: keys[i]) {
                    status[ks] = 1;
                }
            } else {
                ckk.emplace_back(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans += candies[curr];
            
            for (int b: containedBoxes[curr]) {
                seen[b] = true;
                if (status[b]) {
                    for (int ks: keys[b]) {
                        status[ks] = 1;
                    }
                    q.push(b);
                    join[b] = true;
                } else {
                    ckk.emplace_back(b);
                }
            }

            for (int i: ckk) {
                if (status[i] && seen[i] && !join[i]) {
                    q.push(i);
                    join[i] = true;
                }
            }
        }
        return ans;
    }
};