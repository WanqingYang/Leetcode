/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // https://leetcode.com/discuss/18263/sharing-my-line-solution-can-someone-make-even-more-concise
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* dummy = l3;   // dummy head, get the list from the beginning
        int sum = 0;
        while(l1 || l2 || sum)
        {
            if(l1)
            {
                sum += l1->val;
                l1 = l1->next;   // ListNode* l1 = l1->next;
            }
            if(l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            l3->next = new ListNode(sum % 10);
            l3 = l3 -> next;
            sum /= 10;
        }
        
       // if(sum == 1){l3->next = new ListNode(1);}    //?????? 

        return dummy->next;
    }
};