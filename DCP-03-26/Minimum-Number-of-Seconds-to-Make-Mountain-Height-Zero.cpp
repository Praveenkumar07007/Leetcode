1class Solution {
2public:
3    bool can(long long T, int h, vector<int>& w) {
4        long long total = 0;
5
6        for (long long t : w) {
7            long long val = (2 * T) / t;
8            long long x = (long long)((sqrt(1 + 4.0 * val) - 1) / 2);
9            total += x;
10            if (total >= h) return true;
11        }
12
13        return false;
14    }
15
16    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
17        long long l = 0, r = 1e18;
18        long long ans = r;
19
20        while (l <= r) {
21            long long mid = l + (r - l) / 2;
22
23            if (can(mid, mountainHeight, workerTimes)) {
24                ans = mid;
25                r = mid - 1;
26            } else {
27                l = mid + 1;
28            }
29        }
30
31        return ans;
32    }
33};