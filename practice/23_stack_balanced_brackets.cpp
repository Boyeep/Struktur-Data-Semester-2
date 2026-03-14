#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int main() {
    string s;
    cin >> s;

    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty() || !isMatching(st.top(), c)) {
                cout << "TIDAK SEIMBANG" << '\n';
                return 0;
            }
            st.pop();
        }
    }

    cout << (st.empty() ? "SEIMBANG" : "TIDAK SEIMBANG") << '\n';
    return 0;
}
