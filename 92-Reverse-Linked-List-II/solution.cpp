/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "lintcode.h"

using namespace std;


class Solution {
public:
    void reverse(ListNode *head) {
        ListNode *prev = NULL;
        while (head != NULL) {
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
    }

    ListNode *findkth(ListNode *head, int k) {
        for (int i = 0; i < k; i++) {
            if (head == NULL) {
                return NULL;
            }
            head = head->next;
        }
        return head;
    }

    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *mth_prev = findkth(dummy, m - 1);
        ListNode *mth = mth_prev->next;
        ListNode *nth = findkth(dummy, n);
        ListNode *nth_next = nth->next;
        nth->next = NULL;

        reverse(mth);
        mth_prev->next = nth;
        mth->next = nth_next;
        return dummy->next;
    }
};