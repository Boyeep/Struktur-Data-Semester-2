#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, int> id;
    id.reserve(n * 2);

    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        id[name] = i;
    }

    vector<int> nxt(n, 0);
    for (int i = 0; i < n; ++i) {
        string from, to;
        cin >> from >> to;
        if (id.count(from) && id.count(to)) {
            nxt[id[from]] = id[to];
        }
    }

    string startName, targetName;
    cin >> startName >> targetName;

    if (!id.count(startName) || !id.count(targetName)) {
        cout << "cooked\n";
        return 0;
    }

    int start = id[startName];
    int target = id[targetName];

    vector<bool> visited(n, false);
    int current = start;

    while (!visited[current]) {
        visited[current] = true;
        current = nxt[current];

        if (current == target) {
            cout << "Oalah, ez ini mah!\n";
            return 0;
        }

        if (current == -1) {
            break;
        }
    }

    cout << "cooked\n";
    return 0;
}
