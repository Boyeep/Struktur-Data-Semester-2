#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
private:
    int* data;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;

public:
    CircularQueue(int cap)
        : data(new int[cap]), capacity(cap), frontIndex(0), rearIndex(0), count(0) {}

    ~CircularQueue() {
        delete[] data;
    }

    void enqueue(int value) {
        if (count == capacity) {
            cout << "Circular queue penuh" << '\n';
            return;
        }
        data[rearIndex] = value;
        rearIndex = (rearIndex + 1) % capacity;
        ++count;
    }

    void dequeue() {
        if (count == 0) {
            cout << "Circular queue kosong" << '\n';
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        --count;
    }

    void front() const {
        if (count == 0) {
            cout << "Circular queue kosong" << '\n';
            return;
        }
        cout << data[frontIndex] << '\n';
    }

    void print() const {
        if (count == 0) {
            cout << "Circular queue kosong" << '\n';
            return;
        }
        for (int i = 0; i < count; ++i) {
            int index = (frontIndex + i) % capacity;
            cout << data[index] << (i + 1 == count ? '\n' : ' ');
        }
    }
};

int main() {
    int capacity, q;
    cin >> capacity >> q;

    CircularQueue cq(capacity);
    while (q--) {
        string command;
        cin >> command;

        if (command == "enqueue") {
            int x;
            cin >> x;
            cq.enqueue(x);
        } else if (command == "dequeue") {
            cq.dequeue();
        } else if (command == "front") {
            cq.front();
        } else if (command == "print") {
            cq.print();
        }
    }

    return 0;
}
