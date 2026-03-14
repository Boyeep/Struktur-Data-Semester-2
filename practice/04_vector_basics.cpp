#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3};

    numbers.push_back(4);
    numbers.insert(numbers.begin() + 1, 10);
    numbers.erase(numbers.begin());

    cout << "vector contents: ";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << ' ';
    }
    cout << '\n';

    int target = 10;
    bool found = false;
    for (int x : numbers) {
        if (x == target) {
            found = true;
            break;
        }
    }

    cout << "contains 10: " << (found ? "yes" : "no") << '\n';
    return 0;
}
