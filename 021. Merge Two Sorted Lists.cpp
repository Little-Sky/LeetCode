// O(n)
// Faster than: 22% - 65%

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0), * head = &dummy;
        while (l1 || l2) {
            int l1_val = l1 ? l1->val : INT_MAX;
            int l2_val = l2 ? l2->val : INT_MAX;
            if (l1_val <= l2_val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        return dummy.next;
    }
};
