/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class solution{
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    //handle case for empty list
    if(head == NULL){
        return NULL;
    }
    //handle special case for one node list
    if(head->next == NULL){
        return head;
    }
    //handle input values of m & n , if m==n - no need to do anything 
    if(m >= n){
        return head;
    }

    struct ListNode * prev  = head;    
    struct ListNode * curr  = head;
    struct ListNode * next  = head;

    struct ListNode *mTh   = NULL; //mTh node
    struct ListNode *nTh   = NULL; //nTh node         
    struct ListNode *mPrev = NULL; // node just previous to mTh node
    struct ListNode *nNext = NULL; // node next to the nTh node
    
    for(int i = 1 ; curr != NULL ; i++){

        next = curr->next ;

        if(i == m){
           //when we reach the mTh node, save mTh and mPrevious
            mPrev = prev ; 
            mTh   = curr ; 
        }
        if(i> m && i <= n){    
             //revese links if we fall within the m and n range (include n)
             curr->next = prev;
        }
        if(i == n ){
           //when we reach the nTh node, save nTh and nNext
            nNext = next ;
            nTh   = curr ;  
        }
        prev = curr; 
        curr = next;
    }
    if(m == 1 ){
        //handle special case if head needs to be changed since m==1 
        mTh->next = nNext;
        head = nTh;
    }else{
        mPrev->next  = nTh ; 
        mTh->next = nNext; 
    }
    return head;
  }
};