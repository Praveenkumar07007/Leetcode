class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int usedBit = 0;
        int ans = 0;
        for(;right<n;right++){
            while((usedBit & nums[right])!=0){
                usedBit ^= nums[left];
                left++;
            }
            usedBit |= nums[right];
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};