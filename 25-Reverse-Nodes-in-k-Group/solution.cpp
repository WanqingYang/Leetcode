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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL || head->next == NULL || k==1 || k==0) {return head;}
        int num=0;
        ListNode *new_head = new ListNode(-1);
        new_head->next = head;
        ListNode *cur = new_head, *nex, *pre = new_head;
        while(cur = cur->next) {num++;}
        while(num >= k) {
            cur = pre->next;
            nex = cur->next;
            for(int i = 1;i < k;++i) {
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre = cur;
            num-=k;
        }
        return new_head->next;
    }
};