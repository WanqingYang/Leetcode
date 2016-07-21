/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution{
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){return head;}  //it is "==", not"=", in judgement sentence!!!
        ListNode dummy(0);
        ListNode *pre = &dummy, *cur = head;
        dummy.next = head;
        while(cur){
            if(cur -> val == val){
                ListNode *temp = cur;
                pre -> next = cur -> next;
                cur = pre -> next;
                delete temp;
    
            }
            if(cur == NULL){return head;}
            else{
                cur = cur -> next;
                pre = pre -> next;
            }
        }
        return head;
    }
};