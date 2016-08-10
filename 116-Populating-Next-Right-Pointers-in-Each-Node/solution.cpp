/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
/**Populate each next pointer to point to its next right node. 
 * If there is no next right node, the next pointer should be set to NULL.
 * Initially, all next pointers are set to NULL.
 **/
 /*
 //my solution; too long and wrong
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> store;
        TreeLinkNode *cur = root;
        if(cur){store.push(cur);}
        else{return;}
        
        while(cur -> left){//if left exist, right must exist, for the tree is perfect
            int _size = store.size();
            for(int i = 0; i < _size - 1; i++){
                //get the first element of queue, connect it to the next pointer to its next right node
                TreeLinkNode *node = store.front();
                store.pop();
                node -> next = store.front();
                //store the node( which be removed) 's left and right child(if not null)
                if(node -> left){
                    store.push(node -> left);
                    store.push(node -> right);
                }
            }
            TreeLinkNode* last = store.front();
            //last -> next = NULL;
            if(last -> left){
                store.push(last -> left);
                store.push(last -> right);
            }
            store.pop();
            cur = cur -> left;
        }
    }
};*/

class Solution {
public:
    void connect(TreeLinkNode *root){
        if(!root){return;}
        TreeLinkNode *pre = root, *cur = NULL;
        
        while(pre -> left){ //if pre -> left == NULL, means it gets the last line
            cur = pre;
            while(cur){ //if cur == NULL, means it gets the last node in this line
                cur -> left -> next = cur -> right;
                if(cur -> next){ //if cur -> next exist, then continuing connect; if not exist, it gets the last node
                    cur -> right -> next = cur -> next -> left;
                }
                cur = cur -> next;
            }
            pre = pre -> left;
        }
    }
};