#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<long long> makanan;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        makanan.push(x);
    }

    while (makanan.size() > 1) {
        long long terberat1 = makanan.top();
        makanan.pop();

        long long terberat2 = makanan.top();
        makanan.pop();

        if (terberat1 != terberat2) {
            makanan.push(terberat1 - terberat2);
        }
    }

    if (makanan.empty()) {
        cout << 0 << '\n';
    } else {
        cout << makanan.top() << '\n';
    }

    return 0;
}
