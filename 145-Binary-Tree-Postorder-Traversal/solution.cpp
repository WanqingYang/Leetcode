/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* //iteration
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode* cur = root, *lastNode = NULL;
        
        while(!s.empty() || cur){
            if(cur){
                s.push(cur);
                cur = cur -> left;
            }else{
                TreeNode *top = s.top();
                if(top -> right&& lastNode != top -> right){ //if need print&&back to root
                    cur = top -> right;
                }else{
                    v.push_back(top -> val);
                    lastNode = top;
                    s.pop();
                }
            }
        }
        return v;
    }
};*/

/*//recursion
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        helper(root, v);
        return v;
    }
    
    void helper(TreeNode *p, vector<int> &v){
        if(!p){return;}
        helper(p -> left, v);
        helper(p -> right, v);
        v.push_back(p -> val);
    }
};*/

//Morris Traversal
//需要建立一个临时节点dummy，令其左孩子是root。
//并且还需要一个子过程，就是倒序输出某个节点之间路径上的各个节点。
class Solution {
public:
    void reverseNodes(TreeNode *start, TreeNode *end){
        if(start == end){return;}
        TreeNode *x = start, *y = start -> right, *z;
        while(x != end){
            z = y -> right;
            y -> right = x;
            x = y;
            y = z;
        }
    }
    
    void reverseAddNodes(TreeNode *start, TreeNode *end, vector<int> &v){
        reverseNodes(start, end);
        TreeNode *p = end;
        /*while(p != start){    //do not use this, if p == start at the first time, no push_back
            v.push_back(p -> val);
            p = p -> right;
        }*/
        while(true){
            v.push_back(p -> val);
            if(p == start){break;}
            p = p -> right;
        }
        reverseNodes(end, start);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        TreeNode dummy(0);
        dummy.left = root;
        TreeNode *cur = &dummy, *pre = NULL;
        
        while(cur){
            if(cur -> left == NULL){
                cur = cur -> right;
            }else{
                //find the inorder predecessor
                pre = cur -> left;
                while(pre -> right != NULL && pre -> right != cur){
                    pre = pre -> right;
                }
                if(pre -> right == NULL){
                    pre -> right = cur;
                    cur = cur -> left;
                }else{
                    reverseAddNodes(cur -> left, pre, v); //reverse from cur->left and pre,add to vector using the reversed order
                    pre -> right = NULL;
                    cur = cur -> right;
                }
            }
        }
        return v;
    }
};