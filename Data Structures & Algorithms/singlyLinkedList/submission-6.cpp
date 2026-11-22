class Node {
    public:
        int value;
        Node* next;

    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        Node* current = head;
        int currentIndex = 0;

        while (current != nullptr) {
            if (currentIndex == index) return current->value;
            currentIndex++;
            current = current->next;
        }
        return -1; 
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;

        if (tail == nullptr) tail = newNode;
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool remove(int index) {
        // An empty list or a negative index has nothing to remove.
        if (index < 0 || head == nullptr) return false;

        // Removing the first node requires moving head.
        if (index == 0) {
            Node* temp = head;       // Save the node we're removing.
            head = head->next;      // Make the second node the new head.

            // If the list is now empty, clear tail too.
            if (head == nullptr) tail = nullptr;

            delete temp;            // Free the removed node's memory.
            return true;
        }

        // Walk to the node just BEFORE the index we want to remove
        Node* prev = head;
        for (int i = 0; i < index - 1; i++) {
            if (prev != nullptr) prev = prev->next;
        }

        // The index is out of bounds if there is no node to remove.
        if (prev == nullptr || prev->next == nullptr) return false;

        Node* temp = prev->next;     // Save the node we're removing.
        prev->next = temp->next;     // Link the previous node to the next node.

        // If we removed the last node, the previous node is now the tail.
        if (temp == tail) tail = prev;

        delete temp;                // Free the removed node's memory.
        return true;
    }


    vector<int> getValues() {
        vector<int> res;
        Node* current = head;
        while (current != nullptr) {
            res.push_back(current->value);
            current = current->next;
        }
        return res;
    }
};