// O(logk * n), k is the num of lists, n is the total length
// Faster than 53% - 53%

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> pq;
        ListNode dummy(0), * head = & dummy;
        for (int i=0; i<lists.size(); i++){
            if (lists[i]){
                pq.push(make_pair(-lists[i]->val, lists[i]));
            }
        }
        while (!pq.empty()){
            pair<int, ListNode*> cur = pq.top();
            pq.pop();
            head->next = cur.second;
            head = head->next;
            if (head->next){
                pq.push(make_pair(-head->next->val, head->next));
            }
        }
        return dummy.next;
    }
};
