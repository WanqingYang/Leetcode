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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode *pre = &dummy;
        pre->next = head;
        ListNode *cur = head; //pre, cur are the nodes before the comparing nodes
        
        //for(ListNode *cur = head->next; cur->next != NULL; cur = head, cur = cur->next) {
        while(cur != NULL) {
            if(cur->next != NULL && cur->next->val < cur->val) {
                while(pre->next->val < cur->next->val) {
                    pre = pre->next;
                }
                ListNode *tmp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = tmp;
                
                pre = &dummy;
            } else {
                cur = cur->next;
            }
            
            /*while(pre->next != cur && pre->val < cur->val) {
                before_pre = pre;
                pre = pre->next;
            }
            before_cur->next = cur->next;
            before_pre->next = cur;
            cur->next = pre;
            
            before_cur = cur;
            cur = cur->next;*/
        }
        return dummy.next;
    }
};
 
/*class Solution { 
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode *pre = new_head, *cur = head;
        
        while(cur != NULL){
            if(cur -> next != NULL && cur -> val > cur -> next -> val){
                while(pre -> next -> val < cur -> next -> val){
                    pre = pre -> next;
                }
                // set temp to rellocate the pointer:
                //Insert cur -> next after pre 
                ListNode *temp = pre -> next;        //the order is important
                pre -> next = cur -> next;          //1.pre->next,
                cur -> next = cur -> next -> next; //2.cur->next
                pre -> next -> next = temp;       //3.pre->next->next
                pre = new_head;                  //if change 2&3',no pointer points to cur->next->next
            } else{
                cur = cur -> next;
            }
        }
        ListNode *res = new_head -> next;
        delete new_head;
        return res;
    }
};