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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *fast = head, *slow = head;
        if(head == NULL){return head;}
        for(int i = 0; i < k && fast != NULL; i++){
            fast = fast -> next;
        }
        if(fast == NULL){}
        while(fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }
        ListNode *last = fast -> next, *new_head = slow -> next;
        fast -> next = head;
        slow -> next = last;
        return new_head;
    }
};