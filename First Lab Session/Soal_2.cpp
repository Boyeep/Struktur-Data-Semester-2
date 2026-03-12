#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string dosa = "seru-seruan";

    priority_queue<pair<int, string>> todo;

    for (int i = 0; i < n; i++) {
        int p_num;
        string activity;

        cin >> p_num;
        cin.ignore();
        getline(cin, activity);

        if (activity.find(dosa) != string::npos) {
            // masuk neraka
        } else {
            todo.push({p_num, activity});
        }
    }

    while (!todo.empty()) {
        cout << todo.top().second << '\n';
        todo.pop();
    }

    return 0;
}