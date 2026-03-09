1class Solution {
2public:
3    int M = 1e9 +7;
4
5    int t[201][201][2];
6
7    int solve(int zeroleft,int oneleft, bool lastwasone, int limit){
8        if(zeroleft==0 && oneleft ==0){
9            return 1;
10        }
11
12        if(t[zeroleft][oneleft][lastwasone] != -1) {
13            return t[zeroleft][oneleft][lastwasone];
14        }
15
16        int result = 0;
17
18        if(lastwasone == true){ // exploring zero
19            for(int len = 1;len<=min(zeroleft,limit);len++){
20                result = (result + solve(zeroleft-len, oneleft, false, limit)) % M;
21            }
22        }else{ //exploring one 
23            for(int len = 1;len<=min(oneleft,limit);len++){
24                result = (result + solve(zeroleft, oneleft-len, true, limit)) % M;
25            }
26        }
27        return t[zeroleft][oneleft][lastwasone]=result;
28    }
29
30
31    int numberOfStableArrays(int zero, int one, int limit) {
32        memset(t,-1,sizeof(t));
33        int startwithone = solve(zero, one, false, limit);
34        int startwithzero = solve(zero, one, true, limit);
35        return (startwithone + startwithzero)%M;
36    }
37};