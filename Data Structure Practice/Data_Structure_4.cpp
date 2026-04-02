#include <stdio.h>

#define ll long long

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            ll temp_1 = arr[i];
            ll temp_2 = arr[j];

            if(arr[i] > arr[j]) {
                arr[i] = temp_2;
                arr[j] = temp_1;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}