/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /**If the current (sub)tree contains both p and q, then the function result is their LCA. 
  * If only one of them is in that subtree, then the result is that one of them. 
  * If neither are in that subtree, the result is null/None/nil.
  **/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || root == NULL){
            return root;
        }
        TreeNode *parent1 = lowestCommonAncestor(root -> left, p, q);
        TreeNode *parent2 = lowestCommonAncestor(root -> right, p, q);
        if(parent1 && parent2){return root;}
        return parent1? parent1 : parent2;
    }
};