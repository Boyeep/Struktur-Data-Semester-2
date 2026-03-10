#include <iostream>

int ChangeValue(int x) {
    x = 50;
}

int main() {
    int a = 10;
    std::cout << ChangeValue(a) << '\n';
    

    return 0;
}