class Node {
    public:
        int value;
        Node* prev;
        Node* next;

        Node(int val) {
            this->value = val;
        }
};

class Deque {
public:
    Node* head;
    Node* tail;
    
    Deque() {
        // initialize empty queue: head and tail are nullptr
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        return (head == nullptr);
    }

    void append(int value) {
        // new node added to end of queue (tail)
        // need to update tail after we append
        Node* newNode = new Node(value);
        Node* oldTail = tail;

        newNode->next = nullptr; // end of list

        if (oldTail != nullptr) {
            // we had an existing tail node
            oldTail->next = newNode;
            newNode->prev = oldTail;
        }
        else {
            // list was empty
            newNode->prev = nullptr;
            head = newNode;
        }

        tail = newNode; // update tail
    }

    void appendleft(int value) {
        // new node added to beginning of queue (head)
        // need to update head after we append
        Node* newNode = new Node(value);
        Node* oldHead = head;

        newNode->prev = nullptr; // beginning of list def.

        // handle empty list first
        if (head == nullptr) {
            newNode->next = nullptr;
            tail = newNode;
        }
        else {
            newNode->next = oldHead;
            oldHead->prev = newNode;
        }

        head = newNode; // either way we update head
    }

    int pop() {
        // remove last/rightmost value and return value

        // empty list case
        if (head == nullptr) return -1;

        // single node case: clear head/tail after deletion
        if (head != nullptr && head == tail) {
            int headVal = head->value; // store for later return (could use tail->value too)
            delete head;
            head = nullptr;
            tail = nullptr;
            return headVal;
        }

        // multi node case: second to last node becomes new tail, delete original tail, update new tail->next
        Node* oldTail = tail;
        int tailVal = tail->value;
        tail = tail->prev; // new tail is one before old tail
        tail->next = nullptr; // end of list
        delete oldTail;
        return tailVal;
    }

    int popleft() {
        // remove leftmost node and return value

        // empty list case
        if (head == nullptr) return -1;

        // single node case: clear head/tail after deletion
        if (head != nullptr && head == tail) {
            int headVal = head->value; // store for later return
            delete head;
            head = nullptr;
            tail = nullptr;
            return headVal;
        }

        // multi node case: second node becomes new head, delete original head, update prev
        int headVal = head->value; // store for later return
        Node* oldHead = head;
        head = head->next;
        head->prev = nullptr;
        delete oldHead;
        return headVal;
    }
};
