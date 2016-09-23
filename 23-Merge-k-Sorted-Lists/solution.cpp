/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//priority_queue
//由于priority queue的大小为始终为k，而每次插入的复杂度是log k，一共插入过nk个节点。
//时间复杂度为O(nlogk)，空间复杂度为O(k)。
class Solution {
    struct cmp {
        bool operator()(ListNode *left, ListNode *right) {
            return left->val > right->val;
        }
    };
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()) {return NULL;}
        
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {pq.push(lists[i]);}
        }
        
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while(!pq.empty()) {
            cur->next = pq.top();
            cur = cur->next; //do not forget
            pq.pop();
            if(cur->next != NULL) {
                pq.push(cur->next);
            }
        }
        return dummy.next;
    }
};
 
/*class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    /*ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (NULL == l1) return l2;
        else if (NULL == l2) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }

        return lists.front();
    }
};
