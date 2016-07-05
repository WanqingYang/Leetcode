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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head->next == NULL || m == n){return head;}
        ListNode* first = new ListNode(0);
        first->next = head;
        ListNode* second = first;
        ListNode* pre = first;
        for(int i = 0; i < m-1; ++i){
            first = first->next;
        }
        ListNode* cur = first->next;
        for(int j = 0; j < n-m; ++j){
            ListNode* second = cur->next;
        }
        cur->next = second->next;
        second->next = first->next;
        first->next = second;
        return pre->next;
    }
};