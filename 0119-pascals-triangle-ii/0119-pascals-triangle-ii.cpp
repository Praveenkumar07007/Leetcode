class Solution {
public:
    long long getnCr(int n,int r){
        long long ans=1;
        for(int i=0;i<r;i++){
            ans *= n-i;
            ans /= i+1;
        }
        return ans;
    }
    vector<int> getRow(int n) {
        vector<int> res;
        for(int i=0;i<n+1;i++){
            res.push_back(getnCr(n,i));
        }
        return res;
    }
};