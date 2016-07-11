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
    ListNode* removeElements(ListNode* head, int val) {
        if(head = NULL){return head;}
        ListNode *dummy = head;
        while(head){
            if(head -> val == val){
                ListNode* temp = head;
                head = head -> next;
                delete temp;
            }else{
                head = head -> next;
            }
        }
        return dummy;
    }
};