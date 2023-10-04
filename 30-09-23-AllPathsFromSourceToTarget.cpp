/*
    Time O(V+E)
    Space O(V)
     https://leetcode.com/problems/all-paths-from-source-to-target/description/
*/

class Solution {
   public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> currentAns;
        currentAns.push_back(0);
        dfs(0, graph, ans, currentAns);

        return ans;
    }

    void dfs(int currentNode, vector<vector<int>>& graph,
             vector<vector<int>>& ans, vector<int>& currentAns) {
        if (currentNode == graph.size() - 1) {
            ans.push_back(currentAns);
            return;
        }

        for (int i = 0; i < graph[currentNode].size(); i++) {
            currentAns.push_back(graph[currentNode][i]);
            dfs(graph[currentNode][i], graph, ans, currentAns);
            currentAns.pop_back();
        }
    }
};