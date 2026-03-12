#include <stdio.h>

int sum_array(int *arr, int n) {
    int res = 0;
    for(int i = 0; i < n; i++) {
        res += *(arr + i);
    }
    return res;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = sum_array(arr, n);
    printf("%.2f\n", (float)result);
    return 0;
}