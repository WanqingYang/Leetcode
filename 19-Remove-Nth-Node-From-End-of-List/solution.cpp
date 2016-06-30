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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* front = new ListNode(0);
        front->next = head;
        ListNode* prev = front;
        ListNode* post = front;
        while (prev != nullptr){
            prev = prev->next;
            if (n<0)    post = post->next;
            n--;
        }
        ListNode* temp = post->next;
        post->next = temp->next;
        delete temp;
        return front->next;
    }
};