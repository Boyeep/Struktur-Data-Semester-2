#include <iostream>
using namespace std;

int main() {
    int value = 42;
    int *ptr = &value;

    cout << "value: " << value << '\n';
    cout << "address of value: " << &value << '\n';
    cout << "ptr stores: " << ptr << '\n';
    cout << "value through ptr: " << *ptr << '\n';

    *ptr = 99;
    cout << "updated value: " << value << '\n';

    return 0;
}
