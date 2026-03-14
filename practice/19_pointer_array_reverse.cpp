#include <iostream>
using namespace std;

void swapByPointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArray(int* arr, int n) {
    int* left = arr;
    int* right = arr + n - 1;

    while (left < right) {
        swapByPointer(left, right);
        ++left;
        --right;
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    reverseArray(arr, n);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i + 1 == n ? '\n' : ' ');
    }

    delete[] arr;
    return 0;
}
