/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /**Say we have 2 arrays, PRE and IN.
  * Preorder traversing implies that PRE[0] is the root node.
  * Then we can find this PRE[0] in IN, say it's IN[5].
  * Now we know that IN[5] is root, so we know that IN[0] - IN[4] is on the left side, IN[6] to the end is on the right side.
  * Recursively doing this on subarrays, we can build a tree out of it 
  **/ 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;
        for(int i = 0; i < inorder.size(); i++){
            inorder_map[inorder[i]] = i;
        }
        return helper(0, 0, inorder.size() - 1, preorder, inorder_map);
    }
    
    TreeNode* helper(int preStart, int inStart, int inEnd, vector<int>& preorder, unordered_map<int,int>& inorder_map){
        //
        if(preStart > preorder.size() - 1 || inStart > inEnd){return NULL;}
        
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inIndex = inorder_map.find(root -> val) -> second;

       /* for(int i = inStart; i <= inEnd; i++){
            if(inorder[i] == root -> val){
                inIndex = i;
            }
        }*/
        root -> left = helper(preStart + 1, inStart, inIndex - 1, preorder, inorder_map);
        root -> right = helper(preStart + inIndex - inStart + 1, inIndex + 1, inEnd, preorder, inorder_map);
        return root;
    }
};