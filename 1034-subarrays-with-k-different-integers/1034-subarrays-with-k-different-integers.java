public class Solution {
    public int subarraysWithKDistinct(int[] nums, int K) {
        return atMost(nums, K) - atMost(nums, K - 1);
    }
    
    private int atMost(int[] nums, int K) {
        int n = nums.length;
        Map<Integer, Integer> freq = new HashMap<>();
        int left = 0;
        int distinct = 0;
        int res = 0;
        for (int right = 0; right < n; right++) {
            int num = nums[right];
            if (freq.getOrDefault(num, 0) == 0) {
                distinct++;
            }
            freq.put(num, freq.getOrDefault(num, 0) + 1);
            while (distinct > K && left <= right) {
                int leftNum = nums[left];
                freq.put(leftNum, freq.get(leftNum) - 1);
                if (freq.get(leftNum) == 0) {
                    distinct--;
                }
                left++;
            }
            res += (right - left + 1);
        }
        return res;
    }
}