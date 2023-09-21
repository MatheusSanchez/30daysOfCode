/*
https://leetcode.com/problems/binary-tree-inorder-traversal/description/
Time: O(n)  n == strs.size()
Space: O(n) || O(h) h == height(Tree)
*/
class Solution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        TreeNode* curr = root;
        vector<int> ans;

        while (curr != NULL || nodeStack.empty() == false) {
            while (curr != NULL) {
                nodeStack.push(curr);
                curr = curr->left;
            }

            curr = nodeStack.top();
            nodeStack.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }

        return ans;
    }
};