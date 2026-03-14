#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int priority;
    Node* next;

    Node(string n, int p) : name(n), priority(p), next(nullptr) {}
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

    void push(const string& name, int priority) {
        Node* node = new Node(name, priority);

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

    void increasePriority(const string& name, int delta) {
        if (head == nullptr) {
            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        while (current != nullptr && current->name != name) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            return;
        }

        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        current->priority += delta;
        current->next = nullptr;

        if (head == nullptr || current->priority > head->priority) {
            current->next = head;
            head = current;
            return;
        }

        Node* walker = head;
        while (walker->next != nullptr && walker->next->priority >= current->priority) {
            walker = walker->next;
        }
        current->next = walker->next;
        walker->next = current;
    }

    void serve() {
        if (head == nullptr) {
            cout << "Priority queue kosong" << '\n';
            return;
        }

        cout << head->name << ' ' << head->priority << '\n';
        Node* removed = head;
        head = head->next;
        delete removed;
    }

    void print() const {
        if (head == nullptr) {
            cout << "Priority queue kosong" << '\n';
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << '[' << current->name << ':' << current->priority << ']';
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
            string name;
            int priority;
            cin >> name >> priority;
            pq.push(name, priority);
        } else if (command == "boost") {
            string name;
            int delta;
            cin >> name >> delta;
            pq.increasePriority(name, delta);
        } else if (command == "serve") {
            pq.serve();
        } else if (command == "print") {
            pq.print();
        }
    }

    return 0;
}
