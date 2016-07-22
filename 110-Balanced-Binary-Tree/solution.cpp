/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //mycode,recursion,wrong cause, I just consider the bottom case, fail to consider bigger
 //when from bottom up, may not be balanced
/*class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root){return true;}
        if(!(root -> left)){
            TreeNode* right = root -> right;
            if(!(right) || (!(right -> left) && !(right -> right))){return true;}
            return false;
        }
        if(!(root -> right)){
            TreeNode* left = root -> left;
            if(!(left) || (!(left -> left) && !(left -> right))){return true;}
            return false;            
        }
        return isBalanced(root -> left) && isBalanced(root -> right);
    }
};*/

//bottom up solution
class Solution {
public:
    int depth(TreeNode* cur){
        if(!cur ){return 0;}
        return max(depth(cur -> left), depth(cur -> right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root){return true;}
        int left = depth(root -> left);
        int right = depth(root -> right);
        return abs(left - right) < 2 && isBalanced(root -> left) && isBalanced(root -> right);
    }
};

//top down, DFS
/*class Solution {
public:
    bool isBalanced(TreeNode* root) {
        
    }
};