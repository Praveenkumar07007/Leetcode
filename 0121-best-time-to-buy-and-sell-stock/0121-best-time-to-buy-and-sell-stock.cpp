class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int minp = arr[0];
        int ans = 0;
        for(int i=0;i<n;i++){
            int cost = arr[i]-minp;
            ans = max(ans,cost);
            minp = min(minp,arr[i]);
        }
        return ans;
    }
};
