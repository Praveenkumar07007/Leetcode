public class Solution {
    public int numSubarraysWithSum(int[] nums, int S) {
        int n = nums.length;
        int[] prefix = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        Map<Integer, Integer> count = new HashMap<>();
        int res = 0;
        for (int i = 0; i <= n; i++) {
            if (count.containsKey(prefix[i] - S)) {
                res += count.get(prefix[i] - S);
            }
            count.put(prefix[i], count.getOrDefault(prefix[i], 0) + 1);
        }
        return res;
    }
}