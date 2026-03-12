1class Solution {
2public:
3
4    struct DSU {
5        vector<int> parent;
6        int groups;
7
8        DSU(int n) {
9            parent.resize(n);
10            for (int i = 0; i < n; i++) parent[i] = i;
11            groups = n;
12        }
13
14        int find(int node) {
15            if (parent[node] == node) return node;
16            return parent[node] = find(parent[node]);
17        }
18
19        bool unite(int a, int b) {
20            int rootA = find(a);
21            int rootB = find(b);
22
23            if (rootA == rootB) return false;
24
25            parent[rootB] = rootA;
26            groups--;
27            return true;
28        }
29    };
30
31    int maxStability(int n, vector<vector<int>>& edges, int k) {
32        DSU dsu(n);
33
34        vector<int> mustStrength;
35        vector<int> optStrength;
36
37        vector<vector<int>> mustEdges;
38        vector<vector<int>> optEdges;
39
40        for (auto &edge : edges) {
41            if (edge[3] == 1) {
42                mustEdges.push_back(edge);
43            } else {
44                optEdges.push_back(edge);
45            }
46        }
47
48        for (auto &edge : mustEdges) {
49            if (dsu.unite(edge[0], edge[1]) == false) {
50                return -1;
51            }
52            mustStrength.push_back(edge[2]);
53        }
54
55        sort(optEdges.begin(), optEdges.end(),
56        [](auto &a, auto &b) {
57            return (long long)a[2] * 2 > (long long)b[2] * 2;
58        });
59
60        for (auto &edge : optEdges) {
61            if (dsu.unite(edge[0], edge[1]) == true) {
62                optStrength.push_back(edge[2]);
63            }
64        }
65
66        if (dsu.groups > 1) {
67            return -1;
68        }
69
70        sort(optStrength.begin(), optStrength.end());
71
72        int usedUpgrades = 0;
73
74        for (int i = 0; i < optStrength.size() && usedUpgrades < k; i++) {
75            optStrength[i] = optStrength[i] * 2;
76            usedUpgrades++;
77        }
78
79        int minEdgeStrength = INT_MAX;
80
81        for (auto val : mustStrength) {
82            minEdgeStrength = min(minEdgeStrength, val);
83        }
84
85        for (auto val : optStrength) {
86            minEdgeStrength = min(minEdgeStrength, val);
87        }
88
89        return minEdgeStrength;
90    }
91};