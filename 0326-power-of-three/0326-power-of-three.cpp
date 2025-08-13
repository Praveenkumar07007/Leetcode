class Solution {
public:
    bool isPowerOfThree(int n) {

        return n > 0 and 1162261467 % n == 0; // without loops and recursion

        // if(n<=0) return false;
        // while(n%3==0){
        //     n/=3;
        // }
        // return n==1;
    }
};