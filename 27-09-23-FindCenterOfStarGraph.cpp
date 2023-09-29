/*
    Time: O(n)
    Space: O(n)
    https://leetcode.com/problems/find-center-of-star-graph/description/
*/
class Solution {
   public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();

        unordered_map<int, unordered_set<int>> graph;
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }

        for (auto node : graph) {
            if (node.second.size() == n) {
                return node.first;
            }
        }
        return -1;
    }
};

/*
    Time: O(1)
    Space: O(1)
*/
class Solution {
   public:
    int findCenter(vector<vector<int>>& edges) {
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        }

        if (edges[0][1] == edges[1][0] || edges[0][1] == edges[1][1]) {
            return edges[0][1];
        }

        return -13;
    }
};