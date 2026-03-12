#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> pelanggan;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pelanggan.push(x);
    }

    int s;
    cin >> s;

    for (int i = 0; i < s; i++) {
        string status;
        cin >> status;

        if (pelanggan.empty()) {
            break;
        }

        int depan = pelanggan.front();
        pelanggan.pop();

        if (status == "GAGAL") {
            pelanggan.push(depan);
        }
    }

    if (pelanggan.empty()) {
        cout << "KOSONG" << '\n';
    } else {
        while (!pelanggan.empty()) {
            cout << pelanggan.front();
            pelanggan.pop();

            if (!pelanggan.empty()) {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
