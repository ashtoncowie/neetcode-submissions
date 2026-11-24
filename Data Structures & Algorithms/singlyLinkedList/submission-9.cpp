

class Node {
public:
    int value;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        // no nodes: both head and tail are null
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        // want to get currentNode->value at the ith node
        // start with current = head
        // need to make sure we increment a counter; if count > i we are out of bounds, return -1
        // if there's no nodes (head is null) then return -1
        // continue a while loop until currentNode = nullptr
        Node* current = head;
        int count = 0;

        while (current != nullptr) {
            if (count == index) return current->value;
            current = current->next; // move ptr to next node
            count++;
        }
        // we hit end of the list, or the list is empty
        return -1;

    }

    void insertHead(int val) {
        // we want to make a new node that will take the head position
        // existing head needs to become the ->next of the new node
        // head will now always be the addr of the new node
        // tail should stay the same UNLESS there was only one node
        // if it was empty, new node added becomes both head and tail

        Node* newNode = new Node;
        newNode->value = val;
        newNode->next = head;
        head = newNode;

        if (tail == nullptr) tail = newNode;

    }
    
    void insertTail(int val) {
        // add newNode to the end of the list
        // give it value val and next nullptr
        // if empty, head and tail become newNode
        // if >=1 node, tail becomes newNode, head stays same
        Node* newNode = new Node;
        newNode->value = val;
        newNode->next = nullptr;

        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool remove(int index) {
        Node* target = head;

        if (head == nullptr) return false; // handle empty list

        if (index == 0) {
            head = head->next;
            if (head == nullptr) tail = nullptr; // now empty
            delete target;
            return true;
        }

        // >1 nodes and index>0: traverse to node 1 before deletion
        Node* current = head;
        for (int i=0; i<index-1; i++) {
            if (current == nullptr) return false;
            current = current->next;
        }
        if (current == nullptr) return false;
        // we have reached current = node index-1
        if (current->next != nullptr) {
            target = current->next;
            current->next = target->next;

            if (target == tail) tail = current;
            delete target;
            return true;
        }

        return false;
    }


    vector<int> getValues() {
        vector<int> listValues;
        Node* current = head;

        while (current != nullptr) { // will iterate through last node
            listValues.push_back(current->value);
            current = current->next;
        }
        return listValues;
    }

};