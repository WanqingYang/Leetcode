/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution{
public:
    int maxPathSum(TreeNode* root){
        return unitTri(root, 0);
    }
    
    int unitTri(TreeNode* cur, int sum){
        if(!cur){return 0;}
        if(cur -> val < 0){return 0;}
        //cur is not null && cur -> val >= 0 
        sum += cur -> val;
        if(cur -> left){
            if(cur -> left ->val > 0){
                sum += cur -> left -> val;
            }
        }
        if(cur -> right){
            if(cur -> left -> val > 0){
                sum += cur -> right -> val;
            }
        }
        return unitTri(cur -> left, sum) + unitTri(cur -> right, sum);
    }

};
 
/*class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum;
        return sumAllNodes(root);
    }
    
    int sumAllNodes(TreeNode *cur){
        if(!cur){return 0;}
        if(!(cur -> left) && !(cur -> right)){
            return cur -> val;
        }
        return cur->val + sumAllNodes(cur -> left) +
        sumAllNodes(cur -> right);
    }
};