/*
    Time O(V + E + nlogn) -> O(nlogn)
    Space O(V)
    https://leetcode.com/problems/find-eventual-safe-states/description/
*/

class Solution {
#define VISITED 1
#define UNVISITED -1
#define SAFENODE 0

   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> visiteds(graph.size(), UNVISITED);
        vector<int> ans;

        for (int i = 0; i < graph.size(); i++) {
            if (graph[i].size() == 0) {
                visiteds[i] = SAFENODE;
                ans.push_back(i);
            }
        }

        for (int i = 0; i < graph.size(); i++) {
            if (visiteds[i] == UNVISITED) {
                dfsSafeNode(graph, i, visiteds, ans);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }

    bool dfsSafeNode(vector<vector<int>>& graph, int currentNode,
                     vector<int>& visiteds, vector<int>& ans) {
        if (visiteds[currentNode] == SAFENODE) {  // currentNode -> safeNode
            return true;
        }

        visiteds[currentNode] = VISITED;
        bool isThisSafeNode = true;

        for (int i = 0; i < graph[currentNode].size(); i++) {
            if (visiteds[graph[currentNode][i]] == UNVISITED) {
                isThisSafeNode =
                    dfsSafeNode(graph, graph[currentNode][i], visiteds, ans);
            } else if (visiteds[graph[currentNode][i]] == VISITED) {
                isThisSafeNode = false;
            }

            if (isThisSafeNode == false) {
                break;
            }
        }

        if (isThisSafeNode) {
            ans.push_back(currentNode);
            visiteds[currentNode] = SAFENODE;
            return true;
        }

        return false;
    }
};