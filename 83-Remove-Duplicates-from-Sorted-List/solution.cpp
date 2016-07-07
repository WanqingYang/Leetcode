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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){return head;}
        for(ListNode* pre = head, *cur = pre->next; cur != NULL; cur = cur->next){
            if(pre->val == cur->val){
                pre->next = cur->next;
                delete cur;
            } else{
                pre = cur;
            }
        }
        return head;
    }
};