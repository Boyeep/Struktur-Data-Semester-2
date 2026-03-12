#include <bits/stdc++.h>
using namespace std;

void Printf(stack<char> s) {
    vector<char> temp;

    while (!s.empty()) {
        temp.push_back(s.top());
        s.pop();
    }

    if (temp.empty()) {
        cout << '\n';
        return;
    }

    for (int i = temp.size() - 1; i >= 0; i--) {
        cout << temp[i];
        if (i != 0) {
            cout << ' ';
        }
    }

    cout << '\n';
}

int main() {
    int n;
    cin >> n;

    stack<char> Macaron;
    stack<char> Macaron2;

    for (int i = 0; i < n; i++) {
        char Mac;
        cin >> Mac;
        Macaron.push(Mac);
    }

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string Perintah;
        cin >> Perintah;

        if (Perintah == "PULL") {
            int x;
            cin >> x;

            if (x > Macaron.size()) {
                cout << "Macaron Furina tidak sebanyak itu pls!" << '\n';
            } else {
                queue<char> temps;

                for (int j = 1; j < x; j++) {
                    temps.push(Macaron.top());
                    Macaron.pop();
                }

                Macaron2.push(Macaron.top());
                Macaron.pop();

                while (!temps.empty()) {
                    Macaron.push(temps.front());
                    temps.pop();
                }
            }
        } else if (Perintah == "PUT") {
            while (!Macaron2.empty()) {
                Macaron.push(Macaron2.top());
                Macaron2.pop();
            }
        } else {
            cout << "Apa itu? Furina tidak paham!" << '\n';
        }
    }

    Printf(Macaron);
    Printf(Macaron2);

    return 0;
}
