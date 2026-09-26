class LinkedList {
private:
    typedef struct node {
        int val;
        node * next = nullptr; 
    } node;
    node * root = nullptr;
    int cap = 0;
public:
    LinkedList() = default;

    int get(int index) {
        if (index >= cap || index < 0) return -1;
        else {
            node * ptr = root;
            int i = 0;
            while (i != index) {
                ptr = ptr->next;
                i++;
            }
            return ptr->val;
        }
    }

    void insertHead(int val) {
        node * newNode = new node ();
        newNode->val = val;
        newNode->next = root;
        root = newNode;
        cap++;
    }
    
    void insertTail(int val) {
        node * newNode = new node ();
        newNode->val = val;
        newNode->next = nullptr;

        if (root == nullptr) {
            root = newNode;
        }
        else {
            node * ptr = root;
            for (; ptr->next != nullptr; ptr = ptr->next);
            ptr->next = newNode;
        }
        cap++;
    }

    bool remove(int index) {
        node * ptr = root;
        if (index < 0 || index >= cap) return false;
        else if (index == 0) {
            root = root->next;
        }
        else {
            node * prev = ptr;
            int i = 0;
            while (i != index) {
                prev = ptr;
                ptr = ptr->next;
                i++;
            }
            prev->next = ptr->next;
        }
        delete ptr;
        cap--;
        return true;
    }

    vector<int> getValues() {
        vector<int> result;  
        node * ptr = root;
        for (; ptr != nullptr; ptr = ptr->next) {
            result.push_back(ptr->val);
        }
        return result;
    }
};
