1class Solution {
2    public String findDifferentBinaryString(String[] nums) {
3        StringBuilder result = new StringBuilder();
4        for (int i = 0; i < nums.length; i++) {
5            if (nums[i].charAt(i) == '0') {
6                result.append('1');
7            } else {
8                result.append('0');
9            }
10        }
11        return result.toString();
12    }
13}