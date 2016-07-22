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

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;
        stack<TreeNode*> s;
        stack<string> pathStack;
        s.push(root);
        pathStack.push(to_string(root->val));
        
        while (!s.empty()) {
            TreeNode * curNode = s.top(); s.pop();
            string tmpPath = pathStack.top(); pathStack.pop();
            
            if (curNode->left == NULL && curNode->right == NULL) {
                res.push_back(tmpPath); continue;
            }
            
            if (curNode->left != NULL) {
                s.push(curNode->left);
                pathStack.push(tmpPath + "->" + to_string(curNode->left->val));
            }
            
            if (curNode->right != NULL) {
                s.push(curNode->right);
                pathStack.push(tmpPath + "->" + to_string(curNode->right->val));
            }
        }
        
        return res;
    }
};

//recursion
/*class Solution {
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