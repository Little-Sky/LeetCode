// O(n) recursive
// Faster than 15%

/*
  A faster approach is to iterative: using two pointers, whose distance == n
*/

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
    int getNthFromEnd (ListNode* head, int n) {
        if (!head) {
            return 0;
        } else {
            int dist = getNthFromEnd (head->next, n) + 1;
            if (dist == n + 1) {
                head->next = head->next->next;
            }
            return dist;
        }
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0){
            return head;
        }
        return (getNthFromEnd (head, n) == n ? head->next : head);
    }
};
