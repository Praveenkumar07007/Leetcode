class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
       int n=nums.size(),ans=1,val=nums[0],j=0,i=1,len=1;
       while(i<n && j<n)
       {
           if((val&nums[i])==0)
           {
               int index=j+1;
               while(index<i)
               {
                   if(!(nums[i]&nums[index])) ++index;
                   else break;
               }
               if(index==i){ 
                   len=i-j+1;
                   i++;
               }
               else 
                {
                    ans=max(ans,len);
                    j++;
                    val=nums[j];
                    if(i==j) ++i;
                }
           }
           else 
           {
               ans=max(ans,len);
               j++;
               val=nums[j];
               if(i==j) ++i;
           }
       }
       ans=max(ans,len);
       return ans;
    }
};