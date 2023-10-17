/*
    https://leetcode.com/problems/number-of-provinces/submissions/1073841017/

    BFS:
    Time: O(V^2)
    Space: O(V)

    DFS:
    Time: O(V^2)
    Space: O(V)

    UnionFind:
    Time: O(log n)
    Space: O(n)
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
class Solution {

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<int> parents(isConnected.size());

        for(int i = 0; i < parents.size(); i++){
            parents[i] = i;
        }

        for(int i = 0; i < isConnected.size(); i++){
            for(int j = 0; j < isConnected.size(); j++){
                if(isConnected[i][j] == 1){
                    join(parents,i,j);
                }
            }
        }


        int ans = 0;
        for(int i = 0; i < parents.size(); i++){
            if(parents[i] == i){
                ans++;
            }
        }
       

       return ans;
        
    }

    void join(vector<int> &parents, int x, int y){

        x = find(parents,x);
        y = find(parents,y);

        if(x == y){
            return;
        }

        parents[y] = x;
    }

    int find(vector<int> &parents, int x){ 
        if(parents[x] == x){
            return x;
        }

        return (parents[x] = find(parents, parents[x]));
    }
};