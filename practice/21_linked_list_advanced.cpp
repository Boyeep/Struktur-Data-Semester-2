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

    void deleteValue(int value) {
        if (head == nullptr) {
            return;
        }

        if (head->data == value) {
            Node* removed = head;
            head = head->next;
            delete removed;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* removed = current->next;
            current->next = removed->next;
            delete removed;
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;

        while (current != nullptr) {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void printMiddle() const {
        if (head == nullptr) {
            cout << "Linked list kosong" << '\n';
            return;
        }

        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << slow->data << '\n';
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
                cout << ' ';
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

        if (command == "push_back") {
            int x;
            cin >> x;
            list.pushBack(x);
        } else if (command == "delete") {
            int x;
            cin >> x;
            list.deleteValue(x);
        } else if (command == "reverse") {
            list.reverse();
        } else if (command == "middle") {
            list.printMiddle();
        } else if (command == "print") {
            list.print();
        }
    }

    return 0;
}
