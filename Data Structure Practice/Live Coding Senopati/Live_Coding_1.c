#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    float x;
    float total = 0;

    for(int i = 0; i < n; i++) {
        scanf("%f", &x);
        total += x;
    }

    float avg = total / (float)n;

    printf("%.2f\n", total);
    printf("%.2f", avg);

    return 0;
}