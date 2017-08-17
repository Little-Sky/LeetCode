// O(n)
// Faster than 2% - 20%

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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0), *fi, *se;
        dummy.next = head;
        // head is always before the first element to swap
        head = & dummy;
        while (head && head->next && head->next->next){
            fi = head->next;
            se = fi->next;
            // Swap
            head->next = se;
            fi->next = se->next;
            se->next = fi;
            head = fi;
        }
        return dummy.next;
    }
};
