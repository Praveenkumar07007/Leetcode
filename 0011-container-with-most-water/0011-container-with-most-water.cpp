class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int n = height.size();
        int j = n-1;
        int area =0;
        
        while(i<j){
            int b = j-i;
            int h = min(height[i],height[j]);
            area = max(area,b*h);
            if(height[i]>height[j]) j--;
            else i++;
        }
        return area;
    }
};