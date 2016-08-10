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
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> store;
        TreeLinkNode *cur = root;
        if(cur){store.push(cur);}
        
        while(cur -> left && cur -> next){//if left exist, right must exist, for the tree is perfect
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
            if(last -> left){
                store.push(last -> left);
                store.push(last -> right);
            }
            store.pop();
        }
    }
};