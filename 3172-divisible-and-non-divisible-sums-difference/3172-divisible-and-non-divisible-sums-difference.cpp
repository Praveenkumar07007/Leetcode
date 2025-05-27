class Solution {
public:
    int differenceOfSums(int n, int m) {
        int ndivsum = 0;
        int divsum = 0;
        for(int i=0;i<=n;i++){
            if(i%m!=0){
                ndivsum+=i;
            }
            else{
                divsum+=i;
            }
        }
        return ndivsum-divsum;
        
    }
};