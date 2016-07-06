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
    void merge_helper(ListNode *l1, ListNode *l2, ListNode *tail){
    //ListNode* merge_helper(ListNode *l1, ListNode *l2, ListNode *tail){
        if(l1 == NULL || l2 == NULL){return;}
        if(l1->val <= l2->val){
            tail->next = l1;
            l1 = l1->next;
        } else{
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
        merge_helper(l1, l2, tail);
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1->val == NULL && l2->val == 0){return l2;}
        ListNode dummy_head(0);
        ListNode *tail = &dummy_head;
        merge_helper(l1, l2, tail);
        //tail -> next = l1? l1 : l2;  //
        return dummy_head.next;
        
     /*   //ListNode* pre = new ListNode(0);
        ListNode dummy(0);
        ListNode* pre = &dummy;
        ListNode* tail = pre;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1 -> val < l2 -> val){
                tail -> next = l1;
                l1 = l1 -> next;
            } else{
                tail -> next = l2;
                l2 = l2 -> next;
            }
            tail = tail -> next;   //??????
        }
        tail -> next = l1? l1 : l2;
        //ListNode* pre1 = pre->next;
        //delete pre; 
        return pre->next;  */
    }
};