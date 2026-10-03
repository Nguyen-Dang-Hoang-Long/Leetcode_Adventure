/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node
        ListNode dummy (0, head);
        // 2 ptrs start BEHIND head
        ListNode* first = &dummy;
        ListNode *second = &dummy;
        // Move 1st ptr n nodes ahead 2nd ptr
        for (int i = 0; i <= n && first; i++) {
            first=first->next;
        }
        // Then, move both ptrs, when 1st ptr hits null
        // 2nd ptr is exactly n nodes away from end => the remove node
        // we go back 1 node => first->next instead of first => to connect the nodes
        while(first) {
            first=first->next;
            second=second->next;
        }
        // remove node
        ListNode * tmp = second->next; // node to be delete
        second->next = second->next->next;
        delete tmp;
        // return head
        return dummy.next;
    }
};