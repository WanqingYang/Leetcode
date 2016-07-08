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
        ListNode *fast, *slow = head;
        while(fast != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            while(fast != NULL){
                if(fast == slow){return true;}
            }
        }
        return false;
    }
};