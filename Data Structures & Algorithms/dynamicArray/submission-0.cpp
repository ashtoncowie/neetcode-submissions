class DynamicArray {
public:

    int* arr;
    int capacity = 0;
    int currSize = 0;

    DynamicArray(int capacity) {
        arr = new int[capacity];
        this->capacity = capacity;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        // arr[currSize] = n
        if (currSize >= capacity) {
            resize();
            // array has been doubled in size
        }
        arr[currSize] = n;
        currSize++;
    }

    int popback() {
        currSize--;
        return arr[currSize];
    }

    void resize() {
        int newCapacity = capacity * 2;
        int* bigArray = new int[newCapacity];
        for (int i=0; i<capacity; i++) {
            bigArray[i] = arr[i];
        }
        capacity = newCapacity;
        arr = bigArray;
    }

    int getSize() {
        return currSize;
    }

    int getCapacity() {
        return capacity;
    }
};
