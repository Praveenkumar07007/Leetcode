class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> cur,res,prev;
        for(int num:arr){
            cur.clear();
            cur.insert(num);
            for(int x:prev){
                cur.insert(x|num);
            }
            prev = cur;
            res.insert(cur.begin(),cur.end());
        }
        return res.size();
    }
};