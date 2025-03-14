class Solution {
public:
    bool valid(string s, string& p, vector<int>& removable,int mid){
        int sp = p.size();
        int stp = 0;

        for(int i=0;i<mid;i++){
            s[removable[i]]='*';
        }
        for(int i=0;i<s.size();i++){
            if(s[i]==p[stp]){
                stp++;
            }
        }
        return stp==sp;
    }
    int maximumRemovals(string str, string p, vector<int>& removable) {
        int s =0;
        int e = removable.size();
        int mid = 0;
        int ans =0;
        while(s<=e){
            mid = s+ (e-s)/2;
            if(valid(str,p,removable,mid)){
                ans = mid;
                s = mid +1;
            }
            else{
                e = mid -1;
            }
        }
        return ans;

    }
};