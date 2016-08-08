/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //my code
/*class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* pre = NULL, first = NULL, second = NULL;
        vector<TreeNode*> store;
        findElms(cur, pre, first, second);
        swap;
    }
    
    bool findElms(TreeNode *cur, TreeNode* &pre, vector<TreeNode*> &store //TreeNode* &first, TreeNode* &second){
        if(cur == NULL) return true;
        if(!findElms(cur -> left, pre, store)) {
            store.push_back(pre);
            return false;
        }
        if(prev != NULL && pre -> val >= cur -> val){
            store.push_back(pre);
            return false;
        }
        pre = cur;
        return findElms(cur -> right, pre);
    }
};*/


class Solution{
public:
    void recoverTree(TreeNode* root){
        TreeNode *first = NULL, *second = NULL, *pre = new TreeNode(INT_MIN);
        traverse(root, pre, first, second);
        //swap(first,second);
        int temp = first -> val;
        first -> val = second -> val;
        second -> val = temp;
    }
    
    void traverse(TreeNode* cur, TreeNode* & pre, TreeNode* &first, TreeNode* &second){
        if(cur == NULL){return;}
        traverse(cur -> left, pre, first, second);
        if(first == NULL && pre -> val >= cur -> val){
            first = pre;
        }
        if(first != NULL && pre -> val >= cur -> val){
            second = cur;
        }
        pre = cur;
        traverse(cur -> right, pre, first, second);
        //return;
    }
};