class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mini = arr[0];
        int n = arr.size();
        int maxprofit = 0;
        for(int i=1;i<n;i++){
            int cost = arr[i]-mini;
            maxprofit = max(maxprofit,cost);
            mini = min(mini,arr[i]);
        }
        return maxprofit;
    }
};