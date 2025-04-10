class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==target) return true;
            }
        }
        return false;
        */
        int m = matrix.size();
        int n = matrix[0].size();
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int start = 0;
        int end = m*n-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(matrix[mid/n][mid%n]>target){
                end = mid-1;
            }else if(matrix[mid/n][mid%n]<target){
                start = mid+1;
            }else{
                return true;
            }
        }
        return false;
    }
};