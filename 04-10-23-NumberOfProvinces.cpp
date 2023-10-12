/*
    https://leetcode.com/problems/number-of-provinces/submissions/1073841017/

    BFS:
    Time: O(V^2)
    Space: O(V)

    DFS:
    Time: O(V^2)
    Space: O(V)

*/

class Solution {
    bitset<201> visited;

   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;

        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                bfs(i, isConnected);
                provinces++;
            }
        }

        return provinces;
    }

    void bfs(int initialNode, vector<vector<int>>& graph) {
        queue<int> q;
        q.push(initialNode);

        while (!q.empty()) {
            int currentNode = q.front();
            visited[currentNode] = true;
            q.pop();

            for (int i = 0; i < graph[currentNode].size(); i++) {
                if (!visited[i] && graph[currentNode][i] == 1) {
                    q.push(i);
                }
            }
        }
    }
};

class Solution {
    bitset<201> visited;

   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;

        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                dfs(i, isConnected);
                provinces++;
            }
        }

        return provinces;
    }

    void dfs(int currentNode, vector<vector<int>>& graph) {
        visited[currentNode] = true;
        for (int i = 0; i < graph[currentNode].size(); i++) {
            if (!visited[i] && graph[currentNode][i] == 1) {
                dfs(i, graph);
            }
        }
    }
};