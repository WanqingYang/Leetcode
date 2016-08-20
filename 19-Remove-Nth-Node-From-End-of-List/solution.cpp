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

    /*ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = new ListNode(0);
        pre -> next = head;
        ListNode* temp = pre;
         for (int i = 0; i < n; i++)
        {
            head = head -> next;
        }
        while(head != NULL)
        {
            head = head -> next;
            temp = temp -> next;
        }
        delete temp -> next;   // why here?????
        temp -> next = temp -> next -> next;
        return pre -> next;
    }*/
    
    /*
    题意：删除链表中倒数第n个结点，尽量只扫描一遍。
    使用两个指针扫描，当第一个指针扫描到第N个结点后，
    第二个指针从表头与第一个指针同时向后移动，
    当第一个指针指向空节点时，另一个指针就指向倒数第n个结点了
    */    
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode dummy(0);
        ListNode *pre = &dummy;
        pre -> next = head;
        
        for(int i = 0; i < n; i++){
            head = head -> next;
        }
        while(head != NULL){
            head = head -> next;
            pre = pre -> next;
        }
        ListNode* temp = pre->next;
        pre -> next = pre -> next -> next;
        delete temp;
        
        return dummy.next;
    }
};