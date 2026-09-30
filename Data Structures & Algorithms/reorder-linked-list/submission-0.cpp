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
using namespace std;
class Solution {
public:
    void reorderList(ListNode* head) {
        // empty list or 1 member
        if (!head || !head->next) return;

        // 2 ptrs
        ListNode* slow = head;
        ListNode* fast = head;

        // move both
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // split the list
        ListNode* secondList = slow->next;
        slow->next = nullptr;

        // reverse the link list from slow onward and return the head
        ListNode* prev = nullptr;
        ListNode* curr = secondList;
        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev=curr;
            curr=tmp;
        }
        secondList = prev;

        // ptr to assemble
        ListNode *firstList = head;
        while (secondList) {
            // track both
            ListNode* tmp1 = firstList->next;
            ListNode* tmp2 = secondList->next;

            // stitch
            firstList->next = secondList;
            secondList->next = tmp1;

            // next pair of nodes
            firstList = tmp1;
            secondList = tmp2;
        }
    }
};
