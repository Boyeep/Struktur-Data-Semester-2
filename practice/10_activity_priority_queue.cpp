#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    priority_queue<pair<int, string> > pq;

    for (int i = 0; i < n; ++i) {
        int priority;
        string activity;
        cin >> priority;
        cin.ignore();
        getline(cin, activity);

        if (activity.find("seru-seruan") == string::npos) {
            pq.push(make_pair(priority, activity));
        }
    }

    while (!pq.empty()) {
        cout << pq.top().second << '\n';
        pq.pop();
    }

    return 0;
}
