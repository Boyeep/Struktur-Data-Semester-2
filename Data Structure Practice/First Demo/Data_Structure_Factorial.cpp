#include <iostream>

#define ll unsigned long long

ll Factorial(ll* n) {
    if (*n == 0 || *n == 1) {
        return 1;
    }
    ll next = *n - 1;
    return *n * Factorial(&next);
}

int main() {
    ll n;
    std::cin >> n;

    ll res = Factorial(&n);
    
    std::cout << res;

    return 0;
}