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
TreeNode* invertTree(TreeNode* root) {
    if (root) {
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
    }
    return root;
}
/*    TreeNode* invertTree(TreeNode* root) {
        invertSubTree(root -> left, root -> right);
        return root;
    }
    
    void invertSubTree(TreeNode* left, TreeNode* right){
        if(left || right){
            swap(left, right);
        }else{
            return;
        }
        invertSubTree(left -> left, right -> right);
    }*/
};