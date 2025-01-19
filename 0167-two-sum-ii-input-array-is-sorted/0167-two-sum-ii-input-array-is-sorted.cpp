class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>v;
        int n = numbers.size();
        // for(int i=0;i<n;i++){
        //     int f = target - numbers[i];
        //     for(int j=i+1;j<n;j++){                 // TLE
        //         if(numbers[j]==f){
        //             v.push_back(i+1);
        //             v.push_back(j+1);
        //             return v;
        //         }
        //     }
        // }

        int i=0;
        int j= n-1;
        while(i<j){
           if((numbers[i]+numbers[j]) == target){
            return {i+1,j+1};
           }
           else if((numbers[i]+numbers[j])>target){
            j--;
           }
           else{
            i++;
           }
        }


        return v;
    }
};