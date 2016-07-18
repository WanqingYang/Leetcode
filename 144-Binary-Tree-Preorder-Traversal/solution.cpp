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

//iteration
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
};


//Morris Traversal