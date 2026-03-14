#include <iostream>
using namespace std;

void inputArray(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        cin >> *(arr + i);
    }
}

int findMax(const int* arr, int n) {
    int mx = *arr;
    for (int i = 1; i < n; ++i) {
        if (*(arr + i) > mx) {
            mx = *(arr + i);
        }
    }
    return mx;
}

void selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (*(arr + j) < *(arr + minIndex)) {
                minIndex = j;
            }
        }

        int temp = *(arr + i);
        *(arr + i) = *(arr + minIndex);
        *(arr + minIndex) = temp;
    }
}

void printArray(const int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << *(arr + i) << (i + 1 == n ? '\n' : ' ');
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    inputArray(arr, n);

    cout << "Max: " << findMax(arr, n) << '\n';
    selectionSort(arr, n);
    cout << "Sorted: ";
    printArray(arr, n);

    delete[] arr;
    return 0;
}
