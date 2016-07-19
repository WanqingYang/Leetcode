/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //recursion
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> v;
        findPaths(root, sum, path, v);
        return v;
    }
    
    void findPaths(TreeNode *cur, int sum, vector<int> &path, vector<vector<int>> &v){
        if(!cur){return;}
        path.push_back(cur -> val);   //remember to store the value
        if(!(cur -> left) && !(cur -> right) && cur -> val == sum){ //when find the complete path
            v.push_back(path);
        }
        findPaths(cur -> left, sum - cur -> val, path, v);
        findPaths(cur -> right, sum - cur -> val, path, v);
        path.pop_back(); // remember to pop_back the last element, when return to previous TreeNode*
    }
};