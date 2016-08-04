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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0, 0, inorder.size() - 1, preorder, inorder);
    }
    
    TreeNode* helper(int preStart, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder){
        if(preStart > preorder.size() - 1 || inStart > inEnd){return NULL;}
        
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inIndex = 0;
        //next acculate Index of current root in inorder
        for(int i = inStart; i <= inEnd; i++){
            if(inorder[i] == root -> val){
                inIndex = i;
            }
        }
        //TreeNode *root = new TreeNode(inorder[inIndex]);
        root -> left = helper(preStart + 1, inStart, inIndex - 1, preorder, inorder);
        root -> right = helper(preStart + inIndex - inStart + 1, inIndex + 1, inEnd, preorder, inorder);
        return root;
    }
};