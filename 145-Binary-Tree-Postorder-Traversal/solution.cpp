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
/*class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
    }
};*/

//recursion
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
};

/*//Morris Traversal
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
    }
};*/