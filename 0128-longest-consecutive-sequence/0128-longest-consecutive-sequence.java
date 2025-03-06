class Solution {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        int longest = 1;
        if(n==0) return 0;
        HashSet<Integer> st = new HashSet<>();
        for(int i:nums){
            st.add(i);
        }
        for(int num:st){
            if(!st.contains(num-1)){
                int cnt = 1;
                int x = num;
                while(st.contains(x+1)){
                    x=x+1;
                    cnt++;
                }
                longest = Math.max(longest,cnt);
            }
        }
        return longest;
    }
}