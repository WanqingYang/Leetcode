/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //mycode,recursion,wrong cause, I just consider the bottom case, fail to consider bigger
 //when from bottom up, may not be balanced
/*class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root){return true;}
        if(!(root -> left)){
            TreeNode* right = root -> right;
            if(!(right) || (!(right -> left) && !(right -> right))){return true;}
            return false;
        }
        if(!(root -> right)){
            TreeNode* left = root -> left;
            if(!(left) || (!(left -> left) && !(left -> right))){return true;}
            return false;            
        }
        return isBalanced(root -> left) && isBalanced(root -> right);
    }
};*/

//bottom up solution,O(N^2)
/*class Solution {
public:
    int depth(TreeNode* cur){
        if(!cur ){return 0;}
        return max(depth(cur -> left), depth(cur -> right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root){return true;}
        int left = depth(root -> left);
        int right = depth(root -> right);
        return abs(left - right) < 2 && isBalanced(root -> left) && isBalanced(root -> right);
    }
};*/

/**
 * top down, DFS
 * The second method is based on DFS. Instead of calling depth() explicitly for each child node, we
 * return the height of the current node in DFS recursion. When the sub tree of the current node
 * (inclusive) is balanced, the function dfsHeight() returns a non-negative value as the height.
 * Otherwise -1 is returned. According to the leftHeight and rightHeight of the two children, the 
 * parent node could check if the sub tree is balanced, and decides its return value.
 **/
class Solution {
public:
    int dfsHeight(TreeNode *cur){
        if(cur == NULL){return 0;}
        int left = dfsHeight(cur -> left);
        if(left == -1){return -1;}
        int right = dfsHeight(cur -> right);
        if(right == -1){return -1;}
        
        if(abs(left - right) > 1){return -1;}
        return max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};