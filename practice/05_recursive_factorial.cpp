#include <iostream>
using namespace std;

unsigned long long factorial(unsigned long long n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    unsigned long long n;
    cin >> n;
    cout << factorial(n) << '\n';
    return 0;
}
