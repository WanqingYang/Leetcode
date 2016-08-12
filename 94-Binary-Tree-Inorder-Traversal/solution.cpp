/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /**Morris Traversal
  * 
  * 
  * 
  **/ 
 
/* //Morris Traversal
 class Solution {
 public:
     vector<int> inorderTraversal(TreeNode* root){
         TreeNode *cur = root, *pre = NULL;
         vector<int> v;
         while(cur != NULL){
             if(cur -> left == NULL){
                 v.push_back(cur -> val);  //push_back now
                 cur = cur -> right;
             }else{
                 //find predecessor,which is the left subtree's right most child
                 pre = cur -> left;
                 while(pre -> right != NULL && pre -> right != cur){
                     pre = pre -> right;
                 }
                 
                 //connect or disconnect pre and cur
                 if(pre -> right != cur){
                     pre -> right = cur;
                     cur = cur -> left;
                 }else{
                     pre -> right = NULL;
                     v.push_back(cur -> val); //push_back now
                     cur = cur -> right;
                 }
             }
         }
         return v;
     }
 };*/
 
/*//recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        //if(root == NULL){return v;}
        inorder(root, v);
        return v;
    }
    
    void inorder(TreeNode *root, vector<int> &v){ //pass by reference
        if(root == NULL){return;}
        if(root -> left == NULL && root -> right == NULL){
            v.push_back(root -> val);
            return;
        }
        inorder(root -> left, v);
        inorder(root -> right, v);
    }
};*/


//iteration
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vector;
        stack<TreeNode *> stack;
        TreeNode *cur = root;
        
        while(!stack.empty() || cur)
        {
            if(cur)
            {
                stack.push(cur);
                cur = cur -> left;
            }
            else
            {
                TreeNode *pNode = stack.top();
                vector.push_back(pNode->val);
                stack.pop();
                cur = pNode->right;
            }
        }
        return vector;
    }
};