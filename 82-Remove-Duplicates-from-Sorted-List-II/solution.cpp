/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//second time, iteration, how to deal with memory leak
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
        
        //while(cur->next != NULL) {
        while(cur != NULL) {
            while(cur->next != NULL && cur->next->val == cur->val) {
                cur = cur->next;
            }
            if(pre->next == cur) {
                pre = pre->next;
            } else {
                pre->next = cur->next;
                //pre = pre->next;
            }
            cur = cur->next;
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