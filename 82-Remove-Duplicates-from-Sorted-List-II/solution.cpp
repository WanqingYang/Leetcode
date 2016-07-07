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
 ListNode *deleteDuplicate(ListNode *head){
          if(head == nullptr)
             return head;

          ListNode dummy(INT_MIN);
          dummy.next = head;
          ListNode *prev = &dummy, *cur = head;
          while(cur){
             bool duplicated = false;
             while(cur->next && cur->next->val == cur->val){
                     duplicated = true;
                     ListNode *tmp = cur;
                     cur = cur->next;
                     delete tmp;
                   }
             if(duplicated){
                  ListNode *tmp = cur;
                  cur = cur->next;
                  delete tmp;
                  continue;
               }
               prev->next = cur;
               prev = prev->next;
               cur = cur->next;
           }
            prev->next = cur;
            return dummy.next;
     }
};