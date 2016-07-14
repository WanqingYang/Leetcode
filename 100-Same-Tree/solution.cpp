/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //use recursion:
 //base case: if p and q are both NULL, return(if they are the same)
 //recursion: if p,q's value, their left tree, their right tree, are the same, 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL){return p == q;}  //not use 
        return(p -> val == q -> val && isSameTree(p -> left, q -> left) 
        && isSameTree(p -> right, q -> right));
    }
};