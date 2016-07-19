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
};*/

//iteration
/*class Solution{
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum){
        vector<int> path;
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if(root){q.push(root);}
        while(!q.empty()){
            TreeNode *cur = q.front();
            path.push_back(cur -> val);
            if(!(cur -> left) && !(cur -> right) && cur -> val == sum){
                v.push_back(path);
            }
            if(cur -> left){
                //path.push_back(cur -> left -> val);
                cur -> left -> val += cur -> val;
                q.push(cur -> left);
            }
            if(cur -> right){
                //path.push_back(cur -> right -> val);
                cur -> right -> val += cur -> val;
                q.push(cur -> right);
            }
            q.pop();
            path.pop_back();
        }
        return v;
    }
};*/

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        vector<TreeNode*> st;
        TreeNode *pre = NULL, *cur = root;
        int value = 0;
        while (cur || !st.empty()) {
            while (cur) {
                st.push_back(cur);
                value += cur->val;
                cur = cur->left;
            }
            cur = st.back();
            if (!cur->left && !cur->right && value == sum) {
                vector<int> t;
                for (auto i : st) {
                    t.push_back(i->val);
                }
                result.push_back(t);
            }
            if (cur->right && cur->right != pre) {
                cur = cur->right;
            } else {
                pre = cur;
                value -= cur->val;
                st.pop_back();
                cur = NULL;
            }
        }
        return result;
    }
};