#include <deque>
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            cout << arr[dq.front()];
            if (i + 1 < n) {
                cout << ' ';
            }
        }
    }
    cout << '\n';

    delete[] arr;
    return 0;
}
