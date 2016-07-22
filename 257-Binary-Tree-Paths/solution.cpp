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
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> v;
        stack<TreeNode*> st;
        if(root){st.push(root);}
        while(!st.empty()){
            TreeNode *cur = st.top();
            path.push_back(cur -> val);
            if(!(cur -> left) && !(cur -> right)){
                v.push_back(path);
                st.pop();
            }
            if(cur -> left){
                st.push(cur -> left);
            }
            if(cur -> right){
                st.push(cur -> right);
            }
        }
        return v;
    }
};*/

//recursion
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(!root){return result;}
        findPaths(root, result, to_string(root -> val));
        return result;
        
    }
    void findPaths(TreeNode*cur, vector<string> &result, string path){
        if(!(cur -> left) && !(cur -> right)){
            result.push_back(path);
            return;
        }
        if(cur -> left){
            findPaths(cur -> left, result, path + "->" + to_string(cur -> left ->val));
        }
        if(cur -> right){
            findPaths(cur -> right, result, path + "->" + to_string(cur -> right ->val));
        }
    }
};