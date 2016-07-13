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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL){return head;}
        ListNode *slow = head, *fast = head -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        fast = slow -> next;
        slow -> next = NULL;    // do not forget this
        slow = head;
        return merge(sortList(head), sortList(fast));
    }
    
    ListNode* merge(ListNode *l1, ListNode *l2){
        ListNode dummy(0);
        ListNode *l3 = &dummy;
        while(l1 && l2){
            if(l1 -> val < l2 -> val){
                l3 -> next = l1;
                l1 = l1 -> next;
            }else{
                l3 -> next = l2;
                l2 = l2 -> next;
            }
            l3 = l3 -> next;
        }
        if(l1){l3 -> next = l1;}
        else{l3 -> next = l2;}
        return dummy.next;
    }
};