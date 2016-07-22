/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
    int sum; //declare here, cause need it in both function
public:
    int maxPathSum(TreeNode* root) {
        sum = INT_MIN;
        helper(root);
        return sum;
    }
    
    /*** return the max-value-ended-at-cur-node ***/
    int helper(TreeNode* cur){
        if(!cur){return 0;}
        int left = max(0, helper(cur -> left));
        int right = max(0, helper(cur -> right));
        /*** key parts : embedding the max-value-find in the recursion process ***/
        sum = max(sum, left + right + cur -> val);
        /*** get the max-value-ended-at-cur ***/
        return max(left, right) + cur -> val;
    }
};
 
 /*
class Solution{
public:
    int maxPathSum(TreeNode* root){
        if(root && !(root -> left) && !(root ->right)){
            return root -> val;
        }
        return unit(root);
    }
    int unit(TreeNode* cur){
        if(!cur){return 0;}
        if(cur -> val < 0){return 0;}
        return cur -> val + unit(cur -> left) + unit(cur -> right);
    }
    
    /*int unitTri(TreeNode* cur, int sum){
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
    }*/
 
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