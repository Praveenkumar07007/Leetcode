class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int i = 0, cnt = 0, ans = 0;
        for (int j = 0; j < A.size(); ++j) {
            if(A[j]==0) cnt++;
            while (cnt > 1){
                if(A[i]==0) cnt--;
                i++;
            }
                
            ans = max(ans, j - i);
        }
        return ans;
    }
};
