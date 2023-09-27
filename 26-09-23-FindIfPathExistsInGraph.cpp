/*
    Time: O(V+E);
    Space: O(V);
    https://leetcode.com/problems/find-if-path-exists-in-graph/description/
*/

class Solution {
   public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<unordered_set<int>> graph(n);

        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }

        return bfs(graph, source, destination);
    }

    bool bfs(vector<unordered_set<int>>& graph, int source, int destination) {
        vector<bool> visited(graph.size(), false);

        queue<int> toProcess;
        toProcess.push(source);

        while (!toProcess.empty()) {
            source = toProcess.front();
            visited[source] = true;
            toProcess.pop();

            if (destination == source) {
                return true;
            }

            for (auto u : graph[source]) {
                if (visited[u] == false) {
                    toProcess.push(u);
                }
            }
        }

        return false;
    }
};