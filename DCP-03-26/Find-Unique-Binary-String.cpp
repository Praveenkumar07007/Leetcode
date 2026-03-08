1class Solution {
2public:
3    string findDifferentBinaryString(vector<string>& nums) {
4        int n = nums.size();
5        string ans = "";
6        for(int i=0;i<n;i++){
7            char ch = nums[i][i];
8            ans += (ch=='0')? "1" : "0"; 
9        }
10        return ans;
11    }
12};