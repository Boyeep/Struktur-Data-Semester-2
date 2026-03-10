#include <iostream>

#define ll unsigned long long

ll HitungPangkat(ll *x, ll *z) {
    if(*z == 0) {
        return 1;
    }

    ll next = *x;
    ll next2 = *z - 1;
    return *x * HitungPangkat(&next, &next2);
}

int main() {
    ll n, m;
    std::cin >> n >> m;

    ll res = HitungPangkat(&n, &m);

    std::cout << res;

    return 0;
}