/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /**For every house k, there are two options: either to rob it (include this house: i) or not rob it (exclude this house: e).
  * --Include this house:
  * i = num[k] + e (money of this house + money robbed excluding the previous house)
  * 
  * --Exclude this house:
  * e = max(i, e) (max of money robbed including the previous house or money robbed excluding the previous house)
  * (note that i and e of the previous step, that's why we use tmp here to store the previous i when calculating e, to make 
  * O(1) space)
  **/
 //do not know how to write in vector
/*class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = (2,0);
        robSub(root);
        return max(res[0], res[1]);
    }
    
    vector<int> robSub(TreeNode* root){
        if(root == NULL){return vector<int> res = (2,0);}
        
        vector<int> left = robSub(root -> left);
        vector<int> right = robSub(root -> right);
        
        vector<int> res = (2, 0);
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);  //root not robbed
        res[1] = root -> val + left[0] + right[0]; //root robbed
        
        return res;
    }
};*/

//pair
/*class Solution {
public:
    int rob(TreeNode* root){
        pair<int, int> result = robDFS(root);
        return max(result.first, result.second);
    }
    
    pair<int, int> robDFS(TreeNode* root){
        if(root == NULL){return make_pair(0,0);}
        
        auto left = robDFS(root -> left);
        auto right = robDFS(root -> right);
        
        //root is not robbed
        int robNoMe = max()
    }*/
    
class Solution {
public:
    int rob(TreeNode* root) {
        return robDFS(root).second;
    }
    pair<int, int> robDFS(TreeNode* node){
        if( !node) return make_pair(0,0);
        auto l = robDFS(node->left);
        auto r = robDFS(node->right);
        int f2 = l.second + r.second;
        int f1 = max(f2, l.first + r.first + node->val);
        return make_pair(f2, f1);
    }
};