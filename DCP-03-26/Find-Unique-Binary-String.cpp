1class Solution {
2public:
3    string findDifferentBinaryString(vector<string>& nums) {
4        unordered_set<int> st;
5
6        for(string &num:nums){
7            st.insert(stoi(num,0,2));
8        }
9        string result = "";
10        for(int i=0;i<=nums.size();i++){
11            if(st.find(i)==st.end()){
12                result = bitset<16>(i).to_string();
13                break;
14            }
15        }
16
17        return result.substr(16-nums.size());
18
19
20        // int n = nums.size();
21        // string ans = "";
22        // for(int i=0;i<n;i++){
23        //     char ch = nums[i][i];
24        //     ans += (ch=='0')? "1" : "0"; 
25        // }
26        // return ans;
27    }
28};