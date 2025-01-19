class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int longest = 1;
        int count = 0;
        int lastsmall = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]-1 == lastsmall){
                count++;
                lastsmall= nums[i];
            }
            else if(nums[i]!=lastsmall){
                count=1;
                lastsmall = nums[i];
            }
            longest = max(longest,count);
        }
        return longest;
    }
};