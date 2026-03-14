#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }

    void pushFront(int value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
    }

    void pushBack(int value) {
        Node* node = new Node(value);
        if (head == nullptr) {
            head = node;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = node;
    }

    void popFront() {
        if (head == nullptr) {
            cout << "Linked list kosong" << '\n';
            return;
        }

        Node* removed = head;
        head = head->next;
        delete removed;
    }

    bool search(int target) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == target) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void print() const {
        if (head == nullptr) {
            cout << "Linked list kosong" << '\n';
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            current = current->next;
            if (current != nullptr) {
                cout << " -> ";
            }
        }
        cout << '\n';
    }
};

int main() {
    int q;
    cin >> q;

    SinglyLinkedList list;
    while (q--) {
        string command;
        cin >> command;

        if (command == "push_front") {
            int x;
            cin >> x;
            list.pushFront(x);
        } else if (command == "push_back") {
            int x;
            cin >> x;
            list.pushBack(x);
        } else if (command == "pop_front") {
            list.popFront();
        } else if (command == "search") {
            int x;
            cin >> x;
            cout << (list.search(x) ? "FOUND" : "NOT FOUND") << '\n';
        } else if (command == "print") {
            list.print();
        }
    }

    return 0;
}
