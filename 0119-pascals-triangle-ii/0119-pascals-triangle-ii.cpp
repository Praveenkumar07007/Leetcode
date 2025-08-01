class Solution {
public:

    vector<int> getRow(int n) {
        vector<int> row(n + 1);
        row[0] = 1;
        for (int i = 1; i <= n; ++i) {
            row[i] = row[i - 1] * 1LL * (n - i + 1) / i;
        }
        return row;
    }


    // long long getnCr(int n,int r){
    //     long long ans=1;
    //     for(int i=0;i<r;i++){
    //         ans *= n-i;
    //         ans /= i+1;
    //     }
    //     return ans;
    // }
    // vector<int> getRow(int n) {
    //     vector<int> res;
    //     for(int i=0;i<n+1;i++){
    //         res.push_back(getnCr(n,i));
    //     }
    //     return res;
    // }
};