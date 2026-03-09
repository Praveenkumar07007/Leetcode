1class Solution {
2public:
3    int reverse(int n){
4        long long r =0;
5        while(n>0){
6            
7            r*=10;
8            r+=n%10;
9            n/=10;
10        }
11        //if(r>INT_MAX /10|| r<INT_MAX/10) return 0;
12        return (int)r;
13    }
14    bool isPalindrome(int n) {
15        if(n<0) return false;
16        int r = reverse(n);
17        if(n==r) return true;
18        return false;
19    }
20};