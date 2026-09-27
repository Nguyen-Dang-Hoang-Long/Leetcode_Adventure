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
    ListNode* reverseList(ListNode* head) {
        // 0 or 1 node
        if (!head || !head->next) return head;
        // 2+ node
        ListNode * new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
};
