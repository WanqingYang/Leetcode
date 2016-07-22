/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//compare p->val, q->val and root->val
//if both >, move to right subtree and continue to find
//if both <, move to left subtree and continue to find
//else, one in left subtree, another in right subtree, return root
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p -> val < root -> val && q -> val < root -> val){
            return lowestCommonAncestor(root -> left, p, q);
        }
        if(p -> val > root -> val && q -> val > root -> val){
            return lowestCommonAncestor(root -> right, p, q);
        }
        return root;
    }
};