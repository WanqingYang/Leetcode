/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*//my code, wrong
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0, pathSum = 0;
        helper(root, pathSum, sum);
        return sum;
    }
    
    void helper(TreeNode *cur, int &pathSum, int &sum){
        if(cur == NULL){return;}
        if(cur -> left == NULL && cur -> right == NULL){
            pathSum += cur -> val;
            sum += pathSum;
        }
        int pathSum = 0;
        helper(cur -> left, sum);
        helper(cur -> right, sum);
    }
};*/

class Solution{
public:
    int sumNumbers(TreeNode* root) {
        return traverse(root, 0);
    }
    
    int traverse(TreeNode *cur, int parents){
        if(!cur){return 0;}
        int soFar = parents * 10 + cur -> val;
        int sum = traverse(cur -> left, soFar) + traverse(cur -> right, soFar);
        return (sum)? sum : soFar;
    }
};