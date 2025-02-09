class Solution {
    public int countKDifference(int[] nums, int k) {
        int count = 0;  // Ek variable `count` jo answer store karega, initialize kiya 0 se.
        Map<Integer, Integer> map = new HashMap<>(); // Ek HashMap banaya jo number aur uske frequency ko store karega.

        for (int i : nums) {  // Array `nums` ke har element ke liye loop chalayenge.
            map.put(i, map.getOrDefault(i, 0) + 1);  
            // `map.getOrDefault(i, 0) + 1` ka matlab: agar `i` pehle se map me hai, toh uski value leke +1 kar do.
            // Agar nahi hai toh default 0 lekar +1 kar do, aur map me daal do.

            count += map.getOrDefault(i - k, 0) + map.getOrDefault(i + k, 0);
            // Dekhte hain ki `(i-k)` aur `(i+k)` pehle se map me hain ya nahi.
            // Agar hain toh unki frequency `count` me add kar do.
            // Matlab ye check kar raha hai ki koi pair `(x, y)` exist karta hai jisme `|x - y| == k`
        }

        return count;  // Final answer return kar do.
    }
}
