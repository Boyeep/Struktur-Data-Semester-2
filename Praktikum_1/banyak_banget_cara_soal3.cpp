#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    int m;
    cin >> n >> m;

    string st;
    st.reserve(n.size());

    for (char digit : n) {
        while (m > 0 && !st.empty() && st.back() > digit) {
            st.pop_back();
            --m;
        }
        st.push_back(digit);
    }

    while (m > 0 && !st.empty()) {
        st.pop_back();
        --m;
    }

    size_t firstNonZero = 0;
    while (firstNonZero < st.size() && st[firstNonZero] == '0') {
        ++firstNonZero;
    }

    string answer = st.substr(firstNonZero);
    if (answer.empty()) {
        answer = "0";
    }

    cout << answer << '\n';
    return 0;
}
