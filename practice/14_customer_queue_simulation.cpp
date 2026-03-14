#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> customers;
    for (int i = 0; i < n; ++i) {
        int id;
        cin >> id;
        customers.push(id);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string status;
        cin >> status;

        if (customers.empty()) {
            break;
        }

        int front = customers.front();
        customers.pop();

        if (status == "GAGAL") {
            customers.push(front);
        }
    }

    if (customers.empty()) {
        cout << "KOSONG" << '\n';
        return 0;
    }

    while (!customers.empty()) {
        cout << customers.front();
        customers.pop();
        if (!customers.empty()) {
            cout << ' ';
        }
    }
    cout << '\n';
    return 0;
}
