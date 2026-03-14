#include <iostream>
using namespace std;

int sumArray(const int *arr, int n) {
    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += *(arr + i);
    }
    return total;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << sumArray(arr, n) << '\n';

    delete[] arr;
    return 0;
}
