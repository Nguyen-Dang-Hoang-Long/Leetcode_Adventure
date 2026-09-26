class DynamicArray {
private:
    int * array = nullptr;
    int size = 0;
    int cap = 0;
public:

    DynamicArray(int capacity) {
        array = new int [capacity];
        cap = capacity;
    }

    int get(int i) {
        return array[i];
    }

    void set(int i, int n) {
        array[i] = n;
    }

    void pushback(int n) {
        if (size == cap) {
            resize();
        }
        array[size++] = n;
    }

    int popback() {
        int result = array[size - 1];
        size--;
        return result;
    }

    void resize() {
        int newCap = cap * 2;
        int * newArray = new int [newCap];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        cap = newCap;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return cap;
    }
};
