class Solution {
    public int lengthOfLongestSubstring(String s) {
        int i = 0, ans = 0;
        int[] cnt = new int[128]; // ASCII character frequency array

        for (int j = 0; j < s.length(); j++) {
            cnt[s.charAt(j)]++; // Add new character to window
            
            // Shrink the window if a duplicate is found
            while (cnt[s.charAt(j)] > 1) {
                cnt[s.charAt(i)]--;  
                i++;
            }
            
            ans = Math.max(ans, j - i + 1); // Update max window size
        }
        return ans;
    }
}
