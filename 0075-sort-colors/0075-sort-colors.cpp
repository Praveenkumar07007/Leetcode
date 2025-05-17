class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            bool flag = true;
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    flag = false;
                }
            }
            if(flag == true) break;
        }
    }
};