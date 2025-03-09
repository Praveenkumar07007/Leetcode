

class Solution {
    public String minWindow(String s, String t) {
        if (s.length() < t.length()) return ""; 

        HashMap<Character, Integer> map = new HashMap<>();
        for (char c : t.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        int left = 0, right = 0, minLen = Integer.MAX_VALUE, minStart = 0;
        int count = t.length();

        while (right < s.length()) {
            char rightChar = s.charAt(right);
            if (map.containsKey(rightChar)) {
                if (map.get(rightChar) > 0) count--; 
                map.put(rightChar, map.get(rightChar) - 1);
            }
            right++;

            while (count == 0) { // Valid window found
                if (right - left < minLen) {
                    minLen = right - left;
                    minStart = left;
                }

                char leftChar = s.charAt(left);
                if (map.containsKey(leftChar)) {
                    map.put(leftChar, map.get(leftChar) + 1);
                    if (map.get(leftChar) > 0) count++;
                }
                left++;
            }
        }

        return minLen == Integer.MAX_VALUE ? "" : s.substring(minStart, minStart + minLen);
    }
}
