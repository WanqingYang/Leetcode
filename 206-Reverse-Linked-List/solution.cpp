/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head->next == NULL){return head;}
        
        ListNode* pre = head->next;
        //head->next->next = head->next;
        head->next->next = reverseList(pre->next);
        pre->next = head;
        return pre;
    }
};*/

class Solution{
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        //ListNode* temp;
        while(head != NULL){
            ListNode* temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
    
};