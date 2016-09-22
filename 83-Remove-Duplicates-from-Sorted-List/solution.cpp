/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//second time, rewrite
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        for(ListNode *pre = head, *cur = pre->next; cur != NULL; cur = cur->next) {
            if(pre->val == cur->val) {
                pre->next = cur->next;
                delete cur;
                cur = pre;
            } else {
                pre = cur;
            }
        }
        return head;
    }
};

/*class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){return head;}
        //below no need for repeating intialization
        for(ListNode* pre = head, *cur = pre->next; cur != NULL; cur = cur->next){
            if(pre->val == cur->val){
                pre->next = cur->next;
                delete cur;
                cur = pre;
            } else{
                pre = cur;
            }
        }
        return head;
    }
};