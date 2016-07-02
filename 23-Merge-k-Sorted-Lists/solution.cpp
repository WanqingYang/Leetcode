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
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()){return NULL;}
        int len = lists.size();
        while(len > 1){
            for(int i = 0; i < len / 2; i++){
                lists[i] = mergeTwoLists(lists[i], lists[len - i - 1])
            }
            len = (len + 1)/2;
        }
        return lists.front();
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        if(l1 == NULL){return l2}
        else if(l2 == NULL){return l1}
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2)
            return l1;
        } else{
            l2->next = mergeTwoLists(l2->next, l2)
            return l2;
        }
    }
};