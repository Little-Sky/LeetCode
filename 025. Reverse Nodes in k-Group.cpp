// O(n) takes some extra memory
// Faster than: 8% - 39%

/*
  There is a faster method, which does not takes extra memory.
  It recursive swap for k groups. Each time, swap the rest first, then, plug the nodes one-by-one.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> kStack;
        // st, ed is before, after the k group: st [a0, a1, ..., ak] ed
        ListNode dummy(0), *st = &dummy, *ed = head;
        dummy.next = head;
        while (head) {
            for (int i=0; i<k && head; i++) {
                kStack.push(head);
                head = head->next;
            }
            if (kStack.size() < k){
                st->next = ed;
                break;
            }
            ed = head;
            while (!kStack.empty()) {
                ListNode * cur = kStack.top();
                kStack.pop();
                st->next = cur;
                st = st->next;
            }
            st->next = ed;
        }
        return dummy.next;
    }
};
