#include <iostream>

int HitungPangkat(int n, int m) {
    if(m == 0) {
        return 1;
    }
    return n * HitungPangkat(n, m - 1);
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::cout << HitungPangkat(n, m);

    return 0;
}