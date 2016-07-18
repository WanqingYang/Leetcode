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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        //if(root == NULL){return v;} //corner case included in helper function
        helper(root, v);
        return v;
    }
    void helper(TreeNode* p, vector<int> &v){ //must pass by reference, or v will not change
        if(!p){return;}
        v.push_back(p -> val);
        helper(p -> left, v);
        helper(p -> right, v);
    }
};*/

/*//iteration, use stack to imitate recursion
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root){return v;}
        stack<TreeNode*> s; //must use stack, for it is depth first search
        TreeNode* cur = root;
        s.push(root);
        
        while(!s.empty()){
            cur = s.top();
            s.pop();
            v.push_back(cur -> val);
            if(cur -> right){s.push(cur -> right);}//right store earlier, then left, for last in first
            if(cur -> left){s.push(cur -> left);}//out
        }
        return v;
    }
};*/


//Morris Traversal
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        TreeNode *cur = root, *pre = NULL;
        vector<int> v;
        while(cur){
            if(cur -> left == NULL){
                v.push_back(cur -> val);
                cur = cur -> right;
            }
            else{
                //find its inorder predecessor
                pre = cur -> left;
                while(pre -> right != NULL && pre -> right != cur){
                    pre = pre -> right;
                }
                if(pre -> right == NULL){
                    v.push_back(cur -> val);
                    pre -> right = cur;
                    cur = cur -> left;
                }else{
                    pre -> right = NULL;
                    cur = cur -> right;
                }
            }
        }
        return v;
    }
};