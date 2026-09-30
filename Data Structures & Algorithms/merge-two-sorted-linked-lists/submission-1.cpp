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
        // New list head
        ListNode dummy(0);
        ListNode * tail = &dummy;

        // While both lists still have members
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1=list1->next;
                
            }
            else {
                tail->next = list2;
                list2=list2->next;
            }
            tail = tail->next;
        }

        // While one list still remains
        tail->next = list1 ? list1 : list2;

        // return
        return dummy.next;
    }
};
