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
int countAndRemove(struct ListNode *node, int n){

    //Once the stack frame reaches the tail, counting starts.
    if(!node->next) return n-1;

    int NumOfNodesLeft = countAndRemove(node->next, n);

    //If there are exactly n nodes in the rest of the list, delete next node.
    if(NumOfNodesLeft  == 0)  node->next = (node->next)->next;

    //Count decremented.         
    return NumOfNodesLeft - 1;
}

 struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    return (countAndRemove(head, n) == 0)? head->next : head;
  }
};