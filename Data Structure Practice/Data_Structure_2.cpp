#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3};

    for(auto t = a.begin(); t != a.end(); ++t) {
        cout << *t << '\n';
    }

    return 0;
}