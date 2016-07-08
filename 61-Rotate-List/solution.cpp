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
    ListNode* rotateRight(ListNode* head, int k) {
      if(head == nullptr) return head;
      ListNode *cur = head, *new1, *last;
      for(int i = 1; i < k && cur; ++i)
              cur = cur->next;

      new1 = cur->next; last = new1;
      cur->next = nullptr;
      while(last->next)
             last = last->next;
      last->next = head;

      return new1;
    }
};