// O(n) Two iterations
// Faster than 23%

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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0), *le = &dummy, *mid, *ri;
        dummy.next = head;
        while (le->next && le->next->val < x) {
            le = le->next;
        }
        mid = ri = le->next;
        while (ri) {
            if (ri->next && ri->next->val < x) {
                le->next = ri->next;
                ri->next = ri->next->next;
                le = le->next;
                le->next = mid;
            } else {
                ri = ri->next;
            }
        }
        return dummy.next;
    }
};
