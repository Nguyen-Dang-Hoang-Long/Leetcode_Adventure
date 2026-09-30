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
    bool hasCycle(ListNode* head) {
        // If cycle empty
        if (!head) return false;

        // Create a slow and fast ptr
        ListNode* slow = head;
        ListNode* fast = head;

        // While fast hasnt catch up to slow
        while (1) {
            slow = slow->next;
            fast = fast->next;
            // The end is reached => no cycle
            if (fast) fast = fast->next;
            else false;
            // Compare 
            // End is reached => no cycle
            if (!fast) return false;
            // Catch up
            else if (fast->val == slow->val) return true;
        }

        return false;
    }
};
