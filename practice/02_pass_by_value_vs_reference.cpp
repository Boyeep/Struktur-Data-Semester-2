#include <iostream>
using namespace std;

void changeByValue(int x) {
    x = 100;
}

void changeByReference(int &x) {
    x = 100;
}

void changeByReference2(int *x) {
    *x = 100;
}

int main() {
    int a = 10;
    int b = 10;
    int c = 10;

    changeByValue(a);
    changeByReference(b);
    changeByReference2(&c);

    cout << "after changeByValue: " << a << '\n';
    cout << "after changeByReference: " << b << '\n';
    cout << "after changeByReference2: " << c << '\n';

    return 0;
}
