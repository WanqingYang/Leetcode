/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //Bottom up
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
       //calculate the length of list
       int len = 0;
       ListNode *p = head;
       while(p){
           len ++;
           p = p -> next;
       }
       return buildBST(head, 0, len - 1);
    }
    
    //Build Binary Search Tree
    TreeNode *buildBST(ListNode* &list, int start, int end){
        if(start > end){return NULL;}
        int mid = start + (end - start)/2; //same as (start+end)/2, avoid overflow
        //TreeNode *root = new TreeNode(list -> val); //must use new here
        TreeNode *leftChild = buildBST(list, start, mid - 1);//mid is tree val,mid-1 store left
        TreeNode *root = new TreeNode(list -> val); //must use new here
        root -> left = leftChild;
        list = list -> next; //do not forget; to avoid repeating storing nodes
        TreeNode *rightChild = buildBST(list, mid + 1, end);//mid is tree val,mid+1 store right
        root -> right = rightChild;
        return root;
    }
};

//Top down