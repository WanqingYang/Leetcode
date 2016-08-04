/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
//my code
class Solution {
public:
    TreeNode* prev = NULL;
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
};

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
};*/


/**If we use in-order traversal to serialize a binary search tree, we can get a list of values in ascending order. It can be 
 * proved with the definition of BST. And here I use the reference of TreeNode pointer prev as a global variable to mark the 
 * address of previous node in the list.
 **/
 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    //use the reference of TreeNode pointer prev as a global variable to mark the address of previous node in the list.
    //the previous node it is cur's predecessor, inorder traversal, if it is valid, then ascending order
    bool validate(TreeNode* cur, TreeNode* &prev) {
        if (cur == NULL) return true;  //if left subtree's node goes here,return, then last stack, next step is T, ! is F
        if (!validate(cur->left, prev)) return false;
        if (prev != NULL && prev->val >= cur->val) return false; //if prev == NULL, next step, prev = cur
        prev = cur;
        return validate(cur->right, prev);//check its successor
    }
};