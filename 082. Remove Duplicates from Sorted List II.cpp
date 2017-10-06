// O(n)
// Faster than 18%


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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0), *cur = &dummy;
        dummy.next = head;
        while (cur && cur->next) {
            if (cur->next && cur->next->next && cur->next->val == cur->next->next->val) {
                head = cur->next;
                while (head && head->val == cur->next->val) 
                    head = head->next;
                cur->next = head;
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
