/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //second time, another way, think by myself
 //1->2->3->4->5->6->NULL, m = 3, n = 5
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head->next == NULL || m == n) {return head;}//corner case
        //the final head is unknow
        ListNode dummy = ListNode(0);
        ListNode *first = &dummy;
        first->next = head;
        
        for(int i = 0; i < m - 1; i++) {//start at the 0st node, stop at the node before mth
            first = first->next;
        }
        ListNode *third = first->next;
        ListNode *pre = first->next;
        ListNode *cur = pre->next;
        for(int j = 0; j < n - m; j++) {//here n-m=2, 0,1, totol 2times
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        //reconnect the nodes
        first->next = pre;
        third->next = cur;
        return dummy.next;
    } 
};

/*class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head->next == NULL || m == n){return head;}
        ListNode* first = new ListNode(0);
        first->next = head;
        ListNode* pre = first;
        for(int i = 0; i < m-1; ++i){
            first = first->next;
        }
        ListNode* cur = first->next;
        ListNode* second = cur;
        for(int j = 0; j < n-m; ++j){
            second = cur->next;
        }
        cur->next = second->next;
        delete second->next;
        second->next = first->next;
        delete first->next;
        first->next = second;   //?????
        return pre->next;
    }
};