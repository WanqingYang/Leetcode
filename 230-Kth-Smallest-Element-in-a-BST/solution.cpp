/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* //my code; inorder traversal, when print, count++, return when count == k;
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode *cur = root, *pre = NULL;
        int cnt = 0;
        
        while(cur != NULL){
            if(cur -> left == NULL){
                cnt ++;
                if(cnt == k){return cur -> val;}
                cur = cur -> right;
            }else{
                //find its predecessor
                pre = cur -> left;
                while(pre -> right != NULL && pre -> right != cur){
                    pre = pre -> right;
                }
                
                if(pre -> right == NULL){
                    pre -> right = cur;
                    cur = cur -> left;
                }else{ //pre -> right = cur;
                    cnt ++;
                    if(cnt == k){return cur -> val;}
                    pre -> right = NULL;
                    cur = cur -> right;
                }
            }
        }
        return -1;
    }
};*/

/*//inorder recursion
class Solution {
private: int cnt = 0;
private: int number = 0;
public:
    int kthSmallest(TreeNode* root, int k){
        cnt = k;
        helper(root);
        return number;
    }
    void helper(TreeNode *cur){
        if(cur -> left){
            helper(cur -> left);
        }
        //cur -> left == NULL
        cnt --;
        if(cnt == 0){//use 0 here, cause if it judge if(cnt == k), we need another parameter pass in
            number = cur -> val;
            return;
        }
        if(cur -> right){
            helper(cur -> right);
        }
    }
};*/

//inorder, iteration
class Solution{
public:
    int kthSmallest(TreeNode* root, int k){
        stack<TreeNode*> s;
        TreeNode* cur = root;
        if(cur){s.push(cur);}
        int cnt = k;
        
        while(!s.empty()){
            if(cur){
                s.push(cur);
                cur = cur -> left;
            }else{
                cnt --;
                //if(cnt == 0){return cur -> val;}
                TreeNode *p = s.top();
                if(cnt == 0){return p -> val;}
                s.pop();
                cur = p -> right;
            }
        }
        return -1;
    }
};