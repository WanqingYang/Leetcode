/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //second time, rewrite
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) {return head;}
        ListNode small_dh(0), large_dh(0);
        ListNode *small = &small_dh, *large = &large_dh;
        
        while(head) {
            if(head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        small->next = large_dh.next;
        large->next = NULL;
        return small_dh.next;
    } 
};
 
/*class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head -> next == NULL){return head;}
        ListNode small_dh(0), large_dh(0);
        ListNode *small = &small_dh, *large = &large_dh;
        while(head){
            if(head -> val < x){
                small -> next = head;   //new ListNode(head -> val);
                small = small -> next;
            } else{
                large -> next = head;   //new ListNode(head -> val);
                large = large -> next;
            }
            head = head -> next;
        }
        small -> next = large_dh.next;
        large -> next = NULL;  // do not forget
        return small_dh.next;
    }
};