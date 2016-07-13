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
/* //Bottom up
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
        //TreeNode *root = new TreeNode(list -> val); //do not create here,for the next line recursion will continue create new TreeNode
        TreeNode *leftChild = buildBST(list, start, mid - 1);//mid is tree val,mid-1 store left
        TreeNode *root = new TreeNode(list -> val); //must use new here
        root -> left = leftChild;
        list = list -> next; //do not forget; to avoid repeating storing nodes
        TreeNode *rightChild = buildBST(list, mid + 1, end);//mid is tree val,mid+1 store right
        root -> right = rightChild;
        return root;
    }
};*/

//Top down
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head){
        return sortedListToBST1(head, NULL);
    }
    
//private:
    TreeNode *sortedListToBST1(ListNode *head, ListNode *tail){
        if(head == tail){return NULL;}
        if(head -> next == tail){
            TreeNode *root = new TreeNode(head -> val);
            return root;
        }
        //find the middle point
        ListNode *mid = head, *fast = head -> next;
        while(fast != tail && fast -> next != tail){ 
            mid = mid -> next;
            fast = fast -> next -> next;
        }
        TreeNode *root = new TreeNode(mid -> val); //mid, not head
        root -> left = sortedListToBST1(head, mid);
        root -> right = sortedListToBST1(mid -> next, tail);
        return root;
    }
};