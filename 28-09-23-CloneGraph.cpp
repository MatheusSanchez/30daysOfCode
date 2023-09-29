/*
Time: O(V+E)
Space: O(V)
https://leetcode.com/problems/clone-graph/
*/

class Solution {
    bitset<101> visited;
    int maxNode = 101;
    vector<Node*> nodeReference;

   public:
    Solution() : nodeReference(maxNode, nullptr) {}

   public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        Node* myGraph = new Node(node->val);
        nodeReference[node->val] = myGraph;

        dfs(node, myGraph);

        return myGraph;
    }

    void dfs(Node* node, Node* myGraph) {
        if (node == nullptr || visited[node->val] == true) {
            return;
        }

        visited[node->val] = true;

        for (int i = 0; i < node->neighbors.size(); i++) {
            if (nodeReference[node->neighbors[i]->val] == nullptr) {
                Node* dummy = new Node(node->neighbors[i]->val);
                nodeReference[node->neighbors[i]->val] = dummy;
                myGraph->neighbors.push_back(dummy);
            } else {
                myGraph->neighbors.push_back(
                    nodeReference[node->neighbors[i]->val]);
            }
            dfs(node->neighbors[i],
                myGraph->neighbors[myGraph->neighbors.size() - 1]);
        }
    }
};