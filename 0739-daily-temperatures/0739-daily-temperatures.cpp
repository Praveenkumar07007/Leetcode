class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<int>st;
        int n = arr.size();
        vector<int>ans(n,0);
        st.push(0);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]>arr[st.top()]){
                int pos = st.top();
                ans[pos]=i-pos;
                st.pop();
            }
            st.push(i);
        }
        
        return ans;
    }
};