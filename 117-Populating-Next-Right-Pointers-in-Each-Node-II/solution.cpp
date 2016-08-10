/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *head = NULL; //head(first node) of the next level
        TreeLinkNode *pre = NULL; //the leading node(will move) on the next level
        TreeLinkNode *cur = root;//current node of current level
        
        //first while loop:not reaching the last node in the whole tree
        //second while loop:not reaching tha last node in the whole level
        while(cur){
            while(cur){
                //left child
                if(cur -> left){
                    if(pre){ //if pre == NULL, means node in the next level are all finished populating
                        pre -> next = cur -> left; 
                    }else{
                        head = cur -> left;
                    }
                    pre = cur -> left;
                }
                
                //right child
                if(cur -> right){
                    if(pre){
                        pre -> next = cur -> right;
                    }else{
                        head = cur -> right;
                    }
                    pre = cur -> right;
                }
                cur = cur -> next; //move to next node
            }
            //move to next level
            cur = head;
            pre = NULL;
            head = NULL;
        }
    }
};