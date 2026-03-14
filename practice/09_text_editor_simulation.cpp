#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
    int q;
    cin >> q;
    cin.ignore();

    stack<string> words;

    for (int i = 0; i < q; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "WRITE") {
            string word;
            ss >> word;
            words.push(word);
        } else if (command == "BACKSPACE") {
            if (!words.empty()) {
                words.pop();
            }
        } else if (command == "PRINT") {
            stack<string> temp = words;
            vector<string> ordered;
            while (!temp.empty()) {
                ordered.push_back(temp.top());
                temp.pop();
            }
            for (int j = static_cast<int>(ordered.size()) - 1; j >= 0; --j) {
                cout << ordered[j];
                if (j > 0) {
                    cout << ' ';
                }
            }
            cout << '\n';
        }
    }

    return 0;
}
