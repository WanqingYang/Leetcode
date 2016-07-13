/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL){return NULL;}
        // Build the 2nd list by creating a new node for each node in 1st list.
        RandomListNode *newHead, *l1, *l2;
        for(l1 = head; l1 != NULL; l1 = l1 -> next -> next){
            l2 = l1;
            l1 -> next = l2;
        }
        
        // Fix the random pointers in the 2nd list: (Remember that l1->next is actually l2)
        for(l1 = head; l1 != NULL; l1 = l1 -> next -> next){
            if(l1 -> random != NULL){
                l1 -> next -> random = l1 -> random -> next;
            }
        }
        
        // The new head is the 2nd node as that was the first inserted node.
        newHead = head -> next;
        // Separate the combined list into 2: Splice out nodes that are part of second list. 
        for(l1 = head; l1 != NULL; l1 = l1 -> next -> next){
            /*l2 -> next = l1 -> next -> next;
            l2 -> random = l1 -> random -> next;
            l2 = l2 -> next;*/
            
            l2 = l1 -> next;
            l1 -> next = l2 -> next;
            if(l2 -> next != NULL){l2 -> next = l2 -> next -> next;}
        }
        return newHead;
    }
};
/*
class Solution{
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode *newHead, *l1, *l2;
    if (head == NULL) return NULL;

    for (l1 = head; l1 != NULL; l1 = l1->next) {
        l2 = new RandomListNode(l1->label);
        l2->next = l1->random;
        l1->random = l2;
    }
    
    newHead = head->random;
    for (l1 = head; l1 != NULL; l1 = l1->next) {
        l2 = l1->random;
        l2->random = l2->next ? l2->next->random : NULL;
    }
    
    for (l1 = head; l1 != NULL; l1 = l1->next) {
        l2 = l1->random;
        l1->random = l2->next;
        l2->next = l1->next ? l1->next->random : NULL;
    }

    return newHead;
}
};*/