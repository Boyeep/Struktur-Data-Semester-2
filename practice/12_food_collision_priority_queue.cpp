#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<long long> pq;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        pq.push(x);
    }

    while (pq.size() > 1) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        if (a != b) {
            pq.push(a - b);
        }
    }

    cout << (pq.empty() ? 0 : pq.top()) << '\n';
    return 0;
}
