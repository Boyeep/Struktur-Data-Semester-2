#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int awal = 0;
    int terakhir = n - 1;
    int ketemu = 0;

    while(awal <= terakhir && ketemu == 0) {
        int tengah = (awal + terakhir)/2;
        
        if(arr[tengah] == target) {
            ketemu = 1;
            return tengah;
        }
        else if(target < arr[tengah]) {
            terakhir = tengah - 1;
        } else {
            awal = tengah + 1;
        }
        if(ketemu == 1) return tengah;
    }
    
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int target;
    scanf("%d", &target);
    
    int result = binarySearch(arr, n, target);
    printf("%.2f\n", (double)result);
    
    return 0;
}