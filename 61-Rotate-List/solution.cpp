/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /** Since n may be a large number compared to the length of list. So we need to know the length of linked list.After that, move the list after the (l-n%l )th node to the front to finish the rotation.

Ex: {1,2,3} k=2 Move the list after the 1st node to the front
Ex: {1,2,3} k=5, In this case Move the list after (3-5%3=1)st node to the front.
So the code has three parts.
1)Get the length
2)Move to the (l-n%l)th node
3)Do the rotation
  **/
  //second time; rewrite
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *cur = head;
        if(head == NULL) {return head;}
        int len = 1;
        while(cur->next != NULL) {
            cur = cur->next;
            len++;
        }
        ListNode *last = cur->next;// NULL
        cur->next = head;
        k = k % len;
        
        for(int j = 0; j < len - k; j++) {
            cur = cur->next;
        }
        ListNode *new_head = cur->next;
        cur->next = last;
        return new_head;
    }
};

/*class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *fast = head, *slow = head;
        //if(head == NULL || k == 0 || head -> next == NULL){return head;}
        if(head == NULL) {return head;}
        int len = 1;   //calculate number of nodes
        while(fast -> next != NULL){
            fast = fast -> next;
            len++;
        }
        ListNode* last = fast -> next;
        fast -> next = head; // cycle the list
        k = k % len;//???
        for(int j = 0; j < len - k; j++){
            fast = fast -> next;
        }
        ListNode *new_head = fast -> next;
        fast -> next = last;
        return new_head;
    }
};