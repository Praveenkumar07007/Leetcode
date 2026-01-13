class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(n!=m){
            return false;
        }else{
            if(s==t) return true;
        }
        return false;
    }
};