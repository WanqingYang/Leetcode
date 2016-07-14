/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL || (root -> right == NULL && root -> left == NULL)){return true;}
        if(root -> left -> val == root -> right -> val){return true;}
        return(isSymmetric(root -> left) && isSymmetric(root -> right));
    }
};