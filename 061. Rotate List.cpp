// O(n) Two iterations
// Faster than 34%

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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = head ? 1 : 0;
        if (!n) return head;
        ListNode * cur = head;
        while (cur->next) {
            cur = cur->next;
            n++;
        }
        cur->next = head;
        n -= k%n + 1;
        while (n-- ) {
            head = head->next;\
        }
        cur = head->next;
        head->next = NULL;
        return cur;
    }
};
