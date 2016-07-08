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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL){return false;}
        ListNode *fast = head;
        while(fast -> next -> next != NULL){
            fast = fast -> next -> next;
            if(fast == head){return true;}
        }
        return false;
    }
};