/*
https:// leetcode.com/problems/symmetric-tree/description/
Time O(n), n == tree.size();
Space O(h), h == height(tree);
*/

class Solution {
   public:
    bool isSymmetric(TreeNode* root) { return isOk(root->left, root->right); }

    bool isOk(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }

        if (left != nullptr && right != nullptr && left->val == right->val) {
            return isOk(left->left, right->right) &&
                   isOk(left->right, right->left);
        }

        return false;
    }
};