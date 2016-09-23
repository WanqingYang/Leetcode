/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//second time, iteration, dealt with memory leak
//when has duplicate, jump out of while, need another delete, for no duplicates val at all in list
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode dummy(0);
        ListNode *pre = &dummy;
        ListNode *cur = head;
        pre->next = head;
        
        while(cur != NULL) {
            if(cur->next != NULL && cur->next->val == cur->val) {
                while(cur->next != NULL && cur->next->val == cur->val) {
                    ListNode* tmp = cur->next;
                    delete cur;
                    cur = tmp;
                    pre->next = cur;
                }
                tmp = cur->next;
                delete cur;
                cur = tmp;
                pre->next = cur;
            } else{
                cur = cur->next;
                pre = pre->next;
            }
        }
        return dummy.next;
    }
};

/*class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return 0;
        if (!head->next) return head;
        
        int val = head->val;
        ListNode* p = head->next;
        
        if (p->val != val) {
            head->next = deleteDuplicates(p);
            return head;
        } else {
            while (p && p->val == val) p = p->next;
            return deleteDuplicates(p);
        }
    }
};