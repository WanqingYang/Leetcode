/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL){return true;}
        ListNode *pre = NULL, *head_copy = head, *temp;
        while(head){
            temp = head -> next;
            head -> next = pre;
            pre = head;
            head = temp;
        }
        while(pre){
            if(pre -> val == head_copy -> val){
                pre = pre -> next;
                head_copy = head_copy -> next;
            }else{
                return false;
            }
        }
        return true;
    }
};*/


class Solution {
public:
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
    
    bool check(ListNode* p) {
        if (p == NULL) {return true;}
        bool isPal = check(p->next) && (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
};