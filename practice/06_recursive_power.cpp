#include <iostream>
using namespace std;

unsigned long long power(unsigned long long base, unsigned long long exp) {
    if (exp == 0) {
        return 1;
    }
    return base * power(base, exp - 1);
}

int main() {
    unsigned long long base, exp;
    cin >> base >> exp;
    cout << power(base, exp) << '\n';
    return 0;
}
