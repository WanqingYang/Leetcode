/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/*//recursion
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){return 0;}
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
        //return root?  max(maxDepth(root -> left), maxDepth(root -> right)) : 0;
    }
};*/

//level-order traversal using queue
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        queue<TreeNode*> q;
        TreeNode* cur = root;
        if(root){q.push(cur);} //if root is null, then skip this and while below, directly to return
        
        while(!q.empty()){
            int size =q.size();
            for(int i = 0; i < size; ++i){
                TreeNode* temp = q.front();
                if(temp -> left){q.push(temp -> left);}
                if(temp -> right){q.push(temp -> right);}
                q.pop();
            }
            maxDepth++;
        }
        return maxDepth;
    }
};