#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }

    void pushFront(int value) {
        Node* node = new Node(value);
        if (head == nullptr) {
            head = tail = node;
            return;
        }
        node->next = head;
        head->prev = node;
        head = node;
    }

    void pushBack(int value) {
        Node* node = new Node(value);
        if (tail == nullptr) {
            head = tail = node;
            return;
        }
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    void popFront() {
        if (head == nullptr) {
            cout << "DLL kosong" << '\n';
            return;
        }
        Node* removed = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete removed;
    }

    void popBack() {
        if (tail == nullptr) {
            cout << "DLL kosong" << '\n';
            return;
        }
        Node* removed = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete removed;
    }

    void printForward() const {
        if (head == nullptr) {
            cout << "DLL kosong" << '\n';
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            current = current->next;
            if (current != nullptr) {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    void printBackward() const {
        if (tail == nullptr) {
            cout << "DLL kosong" << '\n';
            return;
        }
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data;
            current = current->prev;
            if (current != nullptr) {
                cout << ' ';
            }
        }
        cout << '\n';
    }
};

int main() {
    int q;
    cin >> q;

    DoublyLinkedList dll;
    while (q--) {
        string command;
        cin >> command;

        if (command == "push_front") {
            int x;
            cin >> x;
            dll.pushFront(x);
        } else if (command == "push_back") {
            int x;
            cin >> x;
            dll.pushBack(x);
        } else if (command == "pop_front") {
            dll.popFront();
        } else if (command == "pop_back") {
            dll.popBack();
        } else if (command == "print_forward") {
            dll.printForward();
        } else if (command == "print_backward") {
            dll.printBackward();
        }
    }

    return 0;
}
