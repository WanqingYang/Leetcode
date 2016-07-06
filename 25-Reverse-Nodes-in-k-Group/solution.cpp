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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pre = NULL;
        if(head->next || head->next->next || k = 0){return head;}
        
        int i = 0;
        ListNode* temp = head->next;
        head->next = pre;
        pre = head;
        head = temp;
        ListNode* rest = pre->next;
        
        for(int i = 1; i < k; ++i){
            temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        rest->next = temp;
        return pre;
    }
};