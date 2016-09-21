/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//divide and conquer
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        return mergeList(sortList(head), sortList(fast));
    }
    
private:   
    ListNode *mergeList(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *l3 = &dummy;
        
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                l3->next = l1;
                l1 = l1->next;
            } else {
                l3->next = l2;
                l2 = l2-> next;
            }
            l3 = l3->next;
        }
        l3->next = l1? l1: l2;
        return dummy.next;
    }
};
 
/**Similar with Merge two sorted list
  **/
/*class Solution {
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
        return merge(sortList(head), sortList(fast)); //this makes every two list pass to merge //funtion, the first time, is null or has one ele, so when recursively doing that, every //l1 and l2 before merge funcion, are sorted.
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
        l3->next = l1? l1: l2;
        return dummy.next;
    }
};