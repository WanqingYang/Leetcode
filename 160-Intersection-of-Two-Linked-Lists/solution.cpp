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
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *l1 = headA, *l2 = headB;
    if(l1 == NULL || l2 == NULL){return NULL;}
    while(l1 != NULL && l2 != NULL && l1 != l2){
        l1 = l1 -> next;
        l2 = l2 -> next;
        if(l1 == l2){return l1;}    //if they have the same len: 1.intersection 2.both to end(NULL)
        if(l1 == NULL){l1 = headB;} //if they have diff len: to offset the diff;
        if(l2 == NULL){l2 = headA;}
    }
    return l1; //l1&l2 are the same list
};