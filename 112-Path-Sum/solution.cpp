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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL){return false;}
        if(root -> val == sum && root -> left == NULL && root -> right == NULL){
            return true;
        }
        return hasPathSum(root -> left, sum - root -> val) || 
        hasPathSum(root -> right, sum - root -> val);
    }
};*/

//level-bfs-iterative solution
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum){
        if(root == NULL){return false;}
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur -> left == NULL && cur -> right == NULL){
                if(cur -> val == sum){return true;}
            }
            if(cur -> left){
                cur -> left -> val += cur -> val;
                q.push(cur -> left);
            }
            if(cur -> right){
                cur -> right -> val += cur -> val;
                q.push(cur -> right);
            }
        }
        return false;
    }
};