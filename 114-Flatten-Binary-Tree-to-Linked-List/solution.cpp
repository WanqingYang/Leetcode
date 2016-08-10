/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 //recursion; preorder, which is wrong
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root || (!root->left && !root->right)){return;}
        TreeNode *flatTree = new TreeNode(root->val);
        flattenHelper(root, flatTree);
        root = flatTree;
        return;
    }
    
    void flattenHelper(TreeNode* cur, TreeNode* flatTree){
        if(!cur){
            return;
        }
        
        //construct node and connect it to flatTree
        TreeNode* node = new TreeNode(cur -> val);
        //assume node is the last one, construct its left and right null 
        //node -> left = NULL;
        //node -> right = NULL;
        
        //connect flatTree and node
        flatTree -> left = NULL;
        flatTree -> right = node;
        flatTree = node;
        
        flattenHelper(cur -> left, flatTree);
        flattenHelper(cur -> right, flatTree);
    }
};*/

/*class Solution {
public:
    TreeNode *pre = NULL;
    void flatten(TreeNode* root){
        if(!root){return;}
        flatten(root -> right);
        flatten(root -> left);
        root -> right = pre;
        root -> left = NULL;
        pre = root;
    }
};*/

class Solution {
public:
    void flatten(TreeNode *root) {
		TreeNode*now = root;
		while (now)
		{
			if(now->left)
			{
                //Find current node's prenode that links to current node's right subtree
				TreeNode* pre = now->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = now->right;
                //Use current node's left subtree to replace its right subtree(original right 
                //subtree is already linked by current node's prenode
				now->right = now->left;
				now->left = NULL;
			}
			now = now->right;
		}
    }
};