/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//my code, wrong
/*class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL){return 0;}
        int count = 1;
        int level = 1;
        while(root -> left){
            if(root -> right == NULL){
                level ++;  //do not forget level++, for the level already +1 in the last loop
                count = pow(2,(level - 1));
                return count;
            }else{
                level ++;
            }
            root = root -> left;
        }
        count = pow(2, level) - 1;
        return count;
    }
};*/


/**The height of a tree can be found by just going left. Let a single node tree have height 0. Find the height h of the whole tree. If the whole tree is empty, i.e., has height -1, there are 0 nodes.
 * Otherwise check whether the height of the right subtree is just one less than that of the whole tree, meaning left and right subtree have the same height.
 * 
 *  -If yes, then the last node on the last tree row is in the right subtree and the left subtree is a full tree of height h-1. So we take the 2^h-1 nodes of the left subtree plus the 1 root node plus recursively the number of nodes in the right subtree.
 *  -If no, then the last node on the last tree row is in the left subtree and the right subtree is a full tree of height h-2. So we take the 2^(h-1)-1 nodes of the right subtree plus the 1 root node plus recursively the number of nodes in the left subtree.
 * 
 * Since I halve the tree in every recursive step, I have O(log(n)) steps. Finding a height costs O(log(n)).
 * So overall O(log(n)^2).
 **/ 
class Solution {
public:
    int countNodes(TreeNode* root){
        if(root == NULL){return 0;}
        TreeNode *lTree = root, *rTree = root;
        int height = 0;
        while(rTree){
            lTree = lTree -> left;
            rTree = rTree -> right;
            height ++;
        }
        //left and right subtree have the same height
        if(lTree == NULL){return (1 << height) - 1;} //左移，低位补0，相当于2^(height - 1)
        
        //right subtree's height is less than left subtree
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};

/*
class Solution {

public:

    int countNodes(TreeNode* root) {

        if(!root) return 0;

        int hl=0, hr=0;

        TreeNode *l=root, *r=root;

        while(l) {hl++;l=l->left;}

        while(r) {hr++;r=r->right;}

        if(hl==hr) return pow(2,hl)-1;

        return 1+countNodes(root->left)+countNodes(root->right);

    }

};*/