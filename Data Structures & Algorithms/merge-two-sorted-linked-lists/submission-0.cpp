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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Ptr to track both lists
        ListNode* ptr1 = list1, *ptr2 = list2;

        // Edge case #1: Both list empty => return nullptr
        if (!ptr1 && !ptr2) return nullptr;

        // Edge case #2: One list empty => return the other list => already sorted
        else if (!ptr1) return ptr2;
        else if (!ptr2) return ptr1;

        // New list head
        ListNode* newList = nullptr;
        if (ptr1->val < ptr2->val) {
            newList = ptr1;
            ptr1=ptr1->next;
        }
        else {
            newList = ptr2;
            ptr2=ptr2->next;
        }

        // Dummy to stitch the nodes together
        ListNode * dummy = newList;

        // While both lists still have members
        while (ptr1 && ptr2) {
            if (ptr1->val < ptr2->val) {
                dummy->next = ptr1;
                dummy = dummy->next;
                ptr1=ptr1->next;
                
            }
            else {
                dummy->next = ptr2;
                dummy = dummy->next;
                ptr2=ptr2->next;
            }
        }

        // While one list still remains
        if (!ptr1) dummy->next = ptr2;
        else if (!ptr2) dummy->next = ptr1;

        // return
        return newList;
    }
};
