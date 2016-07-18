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
    int minDepth(TreeNode* root) {
        if(root == NULL){return 0;}
        if(root -> left == NULL){return 1 + minDepth(root -> right);}
        if(root -> right == NULL){return 1 + minDepth(root -> left);}
        return 1 + min(minDepth(root -> left), minDepth(root -> right));
    }
};

/*//leverl-order traversal
class Solution {
public:
    int minDepth(TreeNode* root) {
        int minDepth = 0;
        queue<TreeNode*> q;
        if(root){q.push(root);}
        
        while(!q.empty()){
            minDepth++;
            int size = q.size();
            for(int i = 0; i < size; ++i){
                TreeNode* cur = q.front();
                if(cur -> right == NULL && cur -> left == NULL){
                    return minDepth;
                }
                if(cur -> left){q.push(cur -> left);}
                if(cur -> right){q.push(cur -> right);}
                q.pop();
            }
        }
      return minDepth;  
    }
};