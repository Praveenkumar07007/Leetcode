import java.util.Arrays;

class Solution {
    private boolean allZero(int[] count) {
        for (int num : count) {
            if (num != 0) {
                return false;
            }
        }
        return true;
    }

    public boolean checkInclusion(String pat, String txt) {
        int k = pat.length();
        int[] count = new int[26];

        for (char ch : pat.toCharArray()) {
            count[ch - 'a']++;
        }

        int i = 0, j = 0;
        int n = txt.length();

        while (j < n) {
            int idx = txt.charAt(j) - 'a';
            count[idx]--; 
            if (j - i + 1 == k) {
                if (allZero(count)) {
                    return true; 
                }
                count[txt.charAt(i) - 'a']++;  
                i++; 
            }
            j++; 
        }
        return false; 
    }
}
