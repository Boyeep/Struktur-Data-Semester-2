#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int currentSize;
    int currentCapacity;

    void resizeIfNeeded() {
        if (currentSize < currentCapacity) {
            return;
        }

        currentCapacity *= 2;
        int* next = new int[currentCapacity];
        for (int i = 0; i < currentSize; ++i) {
            next[i] = data[i];
        }
        delete[] data;
        data = next;
    }

public:
    DynamicArray() : data(new int[1]), currentSize(0), currentCapacity(1) {}

    ~DynamicArray() {
        delete[] data;
    }

    void pushBack(int value) {
        resizeIfNeeded();
        data[currentSize++] = value;
    }

    void addToAll(int value) {
        for (int i = 0; i < currentSize; ++i) {
            data[i] += value;
        }
    }

    void popBack() {
        if (currentSize == 0) {
            cout << "kosong woe" << '\n';
            return;
        }
        --currentSize;
    }

    void insertAt(int index, int value) {
        if (index < 0 || index > currentSize) {
            cout << "index tidak valid" << '\n';
            return;
        }

        resizeIfNeeded();
        for (int i = currentSize; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++currentSize;
    }

    void print() const {
        if (currentSize == 0) {
            cout << "gaada isinya :(" << '\n';
            return;
        }
        for (int i = 0; i < currentSize; ++i) {
            cout << data[i] << (i + 1 == currentSize ? '\n' : ' ');
        }
    }
};

int main() {
    int q;
    cin >> q;

    DynamicArray arr;
    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            arr.pushBack(x);
        } else if (type == 2) {
            int x;
            cin >> x;
            arr.addToAll(x);
        } else if (type == 3) {
            arr.popBack();
        } else if (type == 4) {
            arr.print();
        } else if (type == 5) {
            int index, value;
            cin >> index >> value;
            arr.insertAt(index, value);
        }
    }

    return 0;
}
