/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //iteration
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode* cur = root, *lastNode = NULL;
        
        while(!s.empty() || cur){
            if(cur){
                s.push(cur);
                cur = cur -> left;
            }else{
                TreeNode *top = s.top();
                if(top -> right/*need print*/ && lastNode != top -> right/*if back to root*/){
                    cur = top -> right;
                }else{
                    v.push_back(top -> val);
                    lastNode = top;
                    s.pop();
                }
            }

        }
        return v;
    }
};

/*//recursion
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        helper(root, v);
        return v;
    }
    
    void helper(TreeNode *p, vector<int> &v){
        if(!p){return;}
        helper(p -> left, v);
        helper(p -> right, v);
        v.push_back(p -> val);
    }
};*/

/*//Morris Traversal
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
    }
};*/