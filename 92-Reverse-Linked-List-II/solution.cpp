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
        if(head->next == NULL){return head;}
        ListNode* first = new ListNode(0);
        first->next = head;
        ListNode* second = first;
        ListNode* pre = first;
        int i, j = 0;
        //while(head->next != NULL){
            while(i < m - 1){
                first = first->next;
                i++;
            }
            while(j < n - 1){
                second = second->next;
                j++;
            }
             ListNode* temp = first->next;
             ListNode* temp2 = second->next;
             first->next = second->next;
             first->next->next = temp->next;
             second->next = temp;
             second->next->next = temp2->next;
       // }
        return pre;
    }
};