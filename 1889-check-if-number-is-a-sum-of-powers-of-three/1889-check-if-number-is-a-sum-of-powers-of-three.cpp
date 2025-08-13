class Solution {
public:

    bool checkPowersOfThree(int n) {
        while(n>0){
            if(n%3>=2) return false;
            n/=3;
        }
        return true;
    }
    //---------------Backtracking----------------------
    // bool helper(int power,int n){
    //     if(n==0) return true;
    //     if(pow(3,power)>n) return false;
    //     //take
    //     bool addpower = helper(power+1,n-pow(3,power));
    //     //not take
    //     bool skippower = helper(power+1,n);

    //     return addpower||skippower;
    // }
    // bool checkPowersOfThree(int n) {
    //     return helper(0,n);
    // }
};