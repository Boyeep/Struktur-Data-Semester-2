#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        numbers.push_back(x);
    }

    cout << "Forward iteration: ";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << ' ';
    }
    cout << '\n';

    cout << "Reverse iteration: ";
    for (vector<int>::reverse_iterator it = numbers.rbegin(); it != numbers.rend(); ++it) {
        cout << *it << ' ';
    }
    cout << '\n';

    int total = 0;
    for (vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
        total += *it;
    }

    cout << "Sum: " << total << '\n';
    return 0;
}
