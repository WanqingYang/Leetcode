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
    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL/* || head -> next -> next == NULL*/)
        {return;}
        //find the middle point and split into two lists
        ListNode *first = head, *second = head -> next;
        while(second && second -> next){
            first = first -> next;
            second = second -> next -> next;
        }
        
        ListNode *mid = first -> next;
        first -> next = NULL;
        first = head;
        //reverse the second list
        second = NULL;
        ListNode *pre = mid;
        
        while(pre){
            ListNode *temp = pre -> next;
            pre -> next = second;
            second = pre;
            pre = temp;
        }
        //reorder the list
        while(second && first){ //second is shorter than first
            ListNode *first_copy = first -> next;
            first -> next = second;
            ListNode *second_copy = second -> next;
            second -> next = first_copy;
            first = first_copy;
            second = second_copy;
        }
        //if(first){return}
        
    }
};