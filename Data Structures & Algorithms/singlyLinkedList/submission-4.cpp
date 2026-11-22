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
        if (index < 0 || head == nullptr) return false;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            if (head == nullptr) tail = nullptr;
            delete temp;
            return true;
        }

        Node* prev = head;
        for (int i = 0; i < index - 1 && prev; i++) {
            prev = prev->next;
        }

        if (prev == nullptr || prev->next == nullptr) return false;

        Node* temp = prev->next;
        prev->next = temp->next;
        if (temp == tail) tail = prev;
        delete temp;
        return true;
    }

    vector<int> getValues() {
        vector<int> vals = {};
        Node* currNode = head;
        while (currNode != nullptr) {
            vals.push_back(currNode->value);
            currNode = currNode->next;

        }
        return vals;
    }
};

