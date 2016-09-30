/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //second time, rewrite
class Solution{
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        while(head != NULL) {
            ListNode *tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
};
/*class Solution{
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