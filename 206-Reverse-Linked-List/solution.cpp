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
        if (!head || !(head -> next)) return head;
        ListNode* pre = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
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