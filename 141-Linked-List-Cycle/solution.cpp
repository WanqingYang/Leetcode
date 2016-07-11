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
        ListNode *fast = head, *slow = head, *entry = head;
        while(fast->next != NULL && fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next ->next;
            if(fast == slow){
                while(entry != slow){
                    slow = slow -> next;
                    entry = entry -> next;
                }
                return  entry;
            }
        }
        return false;
    }
};