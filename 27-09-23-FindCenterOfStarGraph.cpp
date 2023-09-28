class Solution {
   public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }

        int n = 0;

        for (auto u : graph) {
            if (u.first > n) {
                n = u.first;
            }
        }

        n--;

        for (auto u : graph) {
            if (u.second.size() == n) {
                for (int i = 0; i < n; i++) {
                    if (u.second.find(i + 1) != u.second.end()) {
                        return u.first;
                    }
                }
            }
        }

        return -1;
    }
};