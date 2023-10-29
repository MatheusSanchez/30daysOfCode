/*
    Time O(n) n ==  TREE.size() 
    Space  O(h)  h == TREE.height()
    https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
*/

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        pathSum(root, maxPathSum);
        return maxPathSum;
    }

    int pathSum(TreeNode* root, int &maxPathSum ) {

        if(root == nullptr){
            return 0;
        }



        int leftPath =  pathSum(root->left, maxPathSum); 
        int rightPath = pathSum(root->right, maxPathSum); 
        int maxPath = root->val + max(leftPath,rightPath);

        maxPath = max(maxPath, root->val); 
        maxPath = max(maxPath, root->val+leftPath+rightPath); 

        maxPathSum = max(maxPathSum,  maxPath);
        
        /*
        maxPathSum 
        root->val + left, 
        root->val + right, 
        root->val + left + right, 
        root->val

        // O(n)
        // O(h) == h altura da arvore;
        */
        

        return max(root->val + max(rightPath,leftPath), root->val);
        
    }

    
};