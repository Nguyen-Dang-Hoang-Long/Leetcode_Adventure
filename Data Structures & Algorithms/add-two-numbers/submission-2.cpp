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
private:
    ListNode* reverseList (ListNode* list) {
        if (!list || !list->next) return list;
        ListNode* newHead = reverseList(list->next);
        list->next->next = list;
        list->next = nullptr;
        return newHead;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Both list empty
        if (!l1 && !l2) return nullptr;
        // Head for newlist
        ListNode* newList = nullptr;
        // While at least one list not null
        bool carry = false;
        while (l1 || l2) {
            // Sum with carry
            int sum = 0;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;
            if (carry) {sum++; carry = false;}
            if (sum >= 10) {carry = true; sum -= 10;}   

            // New node
            ListNode* newNode = new ListNode (sum, newList);
            newList = newNode;

            // Next one
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) {
            ListNode* newNode = new ListNode (carry, newList);
            newList = newNode;
        }
        return reverseList(newList);
    }
};
