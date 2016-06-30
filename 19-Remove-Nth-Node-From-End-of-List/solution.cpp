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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode realHead(0);
        realHead.next = head;
        head = &realHead;
        ListNode *curr = &realHead;
        while (n-- > 0)
            curr = curr->next;
        while (curr->next != nullptr) {
            curr = curr->next;
            head = head->next;
        }

        head->next = head->next->next;
        return realHead.next;
    }
};