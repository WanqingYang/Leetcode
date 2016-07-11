/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head -> next == NULL){return head;}
        ListNode small_dh(0), large_dh(0);
        ListNode *small = &small_dh, *large = &large_dh;
        while(head){
            if(head -> val < x){
                small -> next = new ListNode(head -> val);
            } else{
                large -> next = new ListNode(head -> val);
            }
            head = head -> next;
        }
        small -> next = large_dh.next;
        large -> next = NULL;
        return small_dh.next;
    }
};