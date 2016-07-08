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
        if(head == NULL || k == 0 || head -> next == NULL){return head;}
        int len = 1;
        while(fast -> next != NULL){
            fast = fast -> next;
            len++;
        }
        ListNode* last = fast -> next;
        fast -> next = head;                             // cycle the list
        k = k % len;
        for(int j = 0; j < len - k; j++){
            fast = fast -> next;
        }
        ListNode *new_head = fast -> next;
        fast -> next = last;
        return new_head;
    }
};