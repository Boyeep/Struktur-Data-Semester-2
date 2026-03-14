#include <iostream>
#include <string>
using namespace std;

struct Node {
    string value;
    int priority;
    Node* next;

    Node(string v, int p) : value(v), priority(p), next(nullptr) {}
};

class PriorityQueueList {
private:
    Node* head;

public:
    PriorityQueueList() : head(nullptr) {}

    ~PriorityQueueList() {
        while (head != nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }

    void push(const string& value, int priority) {
        Node* node = new Node(value, priority);

        if (head == nullptr || priority > head->priority) {
            node->next = head;
            head = node;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->priority >= priority) {
            current = current->next;
        }

        node->next = current->next;
        current->next = node;
    }

    void pop() {
        if (head == nullptr) {
            cout << "Priority queue kosong" << '\n';
            return;
        }

        Node* removed = head;
        head = head->next;
        delete removed;
    }

    void top() const {
        if (head == nullptr) {
            cout << "Priority queue kosong" << '\n';
            return;
        }

        cout << head->value << ' ' << head->priority << '\n';
    }

    void print() const {
        if (head == nullptr) {
            cout << "Priority queue kosong" << '\n';
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << '[' << current->value << ':' << current->priority << ']';
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

    PriorityQueueList pq;
    while (q--) {
        string command;
        cin >> command;

        if (command == "push") {
            string value;
            int priority;
            cin >> value >> priority;
            pq.push(value, priority);
        } else if (command == "pop") {
            pq.pop();
        } else if (command == "top") {
            pq.top();
        } else if (command == "print") {
            pq.print();
        }
    }

    return 0;
}
