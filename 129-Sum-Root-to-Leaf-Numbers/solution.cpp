/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*class Solution{
public:
    int sumNumbers(TreeNode* root) {
        return traverse(root, 0);
    }
    
    int traverse(TreeNode *cur, int parents){
        if(!cur){return 0;}                   //base case
        int soFar = parents * 10 + cur -> val;//1->2 represents 12
        int sum = traverse(cur -> left, soFar) + traverse(cur -> right, soFar);
        return (sum)? sum : soFar;
        //return sum;
    }
};*/

class Solution{
public:
    int sumNumbers(TreeNode* root) {
        return traverse(root, 0);
    }
    int traverse(TreeNode *cur, int parents){
        if(!cur){return 0;}
        if(!(cur -> left)  && !(cur -> right)){
            return parents * 10 + cur -> val;
        }
        return traverse(cur -> left, 10 * parents + cur -> val) +
        traverse(cur -> right, 10 * parents + cur -> val);
    }
};

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
