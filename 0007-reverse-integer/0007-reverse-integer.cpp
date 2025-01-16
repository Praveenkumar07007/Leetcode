class Solution {
public:
    int reverse(int n) {
        long r=0;
        while(n){
            r*=10;
            r+=(n%10);
            n/=10;

        }
        if(r>INT_MAX || r<INT_MIN) return 0;
        return int(r);
    }
};