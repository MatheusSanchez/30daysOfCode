/*
Time: O(n);
Space: O(2^k); k == altura da arvore
https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
*/

class Solution {
   public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> ans;
        double howMany = 1;
        double nextLevel = 0;
        q.push(root);
        double actualSum = 0;

        while (!q.empty()) {
            nextLevel = 0;
            actualSum = 0;

            for (int i = 0; i < howMany; i++) {
                TreeNode* auxiliar = q.front();
                actualSum += auxiliar->val;
                q.pop();
                if (auxiliar->left != NULL) {
                    nextLevel++;
                    q.push(auxiliar->left);
                }
                if (auxiliar->right != NULL) {
                    nextLevel++;
                    q.push(auxiliar->right);
                }
            }

            ans.push_back(actualSum / howMany);

            howMany = nextLevel;
        }

        return ans;
    }
};