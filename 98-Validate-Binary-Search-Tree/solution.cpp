/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* //recursion
class Solution {
public:
    bool result = true;
    bool isValidBST(TreeNode* root) {
        bool result = true;
        //if(!root){return result}
        return isValidBST(root -> left) && check(root) && isValidBST(root -> right);
    }
    
    bool check(TreeNode* root){
        if(!root){return;}
        if(root -> right == NULL && root -> left != NULL){ //left exist while right not
            result = false;
            return;
        }
        //right,left are exist; but break the rule
        if(root -> left && (root -> val >= root -> right -> val || root -> val <= root -> left -> val)){
            result = false;
            return; 
        }
        helper(result, root -> left);
        helper(result, root -> right);
    }
};*/

class Solution {
private:
    TreeNode* prev=NULL;
public:
    bool isValidBST(TreeNode* root) {
        if(!root)   return true;
        return isValidBST(root->left)  && help(root) && isValidBST(root->right);
    }
    
    bool help(TreeNode* root){
        if(!prev){
            prev=root;
            return true;
        }
        if(prev->val >= root->val)   return false;
        prev=root;
        return true;
    }
};