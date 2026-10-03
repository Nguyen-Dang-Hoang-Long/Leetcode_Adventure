/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Empty list
        if (!head) return nullptr;
        // Dummy node
        Node dummy (0);
        dummy.next = nullptr;
        // None empty list, we iterate and copy all first (no random ptr alloc)
        // We will use a hashmap to match the original nodes with copied ones
        unordered_map<Node*, Node*> deepCopies;
        while (head) {
            // Create new node, copy value
            Node * newNode = new Node(head->val);
            // Create new head
            if (!dummy.next) dummy.next = newNode;
            // Match original node
            deepCopies[head] = newNode;
            head = head->next;
        }
        // Another pass to copy pointers
        for (auto& [og, copy] : deepCopies) {
            if (!og || !copy) continue;
            copy->next = deepCopies[og->next];
            copy->random = deepCopies[og->random];
        }
        return dummy.next;
    }
};