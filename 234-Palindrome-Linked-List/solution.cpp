/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //reverse half of the list
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL){return true;}
        ListNode* fast = head, *slow = head;
        while(fast -> next && fast -> next -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        slow -> next = reverse(slow -> next);//odd list, compare middlenode's left and right
        slow = slow -> next; //right half start at this pointer, do not forget
        while(slow){
            if(slow -> val != head -> val){return false;}
            slow = slow -> next;
            head = head -> next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* rightHead){
        ListNode *pre = NULL, *temp = NULL;
        while(rightHead){
            temp = rightHead -> next;
            rightHead -> next = pre;
            pre = rightHead;
            rightHead = temp;
        }
        return pre;
    }
};
//recursion
/*class Solution {
public:
    ListNode* temp;   //slow pointer, when fast goes to end(null), slow start from head;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
    
    bool check(ListNode* p) {
        if (p == NULL) {return true;}
        bool isPal = check(p->next) && (temp->val == p->val); //??how it worked
        temp = temp->next;
        return isPal;
    }
};*/