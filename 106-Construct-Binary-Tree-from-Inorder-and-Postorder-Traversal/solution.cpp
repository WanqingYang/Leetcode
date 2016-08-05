/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //mycode, wrong
/*class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(postorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }
    
    TreeNode* helper(int postStart, int inStart, int inEnd, vector<int>& inorder, vector<int>& postorder){
        if(postStart < 0 || inStart > inEnd){return NULL;}  //????
        
        TreeNode *root = new TreeNode(postorder[postStart]);
        int inIndex = 0;
        for(int i = inStart; i < inEnd; i++){
            if(inorder[i] == root -> val){
                inIndex = i;
            }
        }
        root -> left = helper(postStart + inIndex - inStart - 1, inStart, inIndex - 1, inorder, postorder);
        root -> right = helper(postStart + inIndex - inStart , inIndex + 1, inEnd, inorder, postorder);
        return root;
    }
};*/

class Solution{
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        unordered_map<int, int> inorder_map;
         // we need a map to look up the position of root in inorder, so
        // that we can divide the tree into separate subtrees,
        // reduces the complexity from n^2 to n assuming good hashing by unodered_map
        for(int i = 0; i < inorder.size(); i ++){
            inorder_map[inorder[i]] = i;
        }
        return buildTreeHelper(inorder_map, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }        
    
    TreeNode* buildTreeHelper(unordered_map<int, int>& inorder_map, int is, int ie, vector<int>& postorder, int ps, int pe){
        if(is > ie || ps > pe){return NULL;}
        int root_val = postorder[pe];
        TreeNode *root =  new TreeNode(root_val);
        int inIndex = inorder_map.find(root_val) -> second;
        int dis = inIndex - is;
        root -> left = buildTreeHelper(inorder_map, is, is + dis - 1, postorder, ps, ps + dis - 1);
        root -> right = buildTreeHelper(inorder_map, is + dis + 1, ie, postorder, ps + dis, pe - 1/*last is root*/);
        return root;
    }
};