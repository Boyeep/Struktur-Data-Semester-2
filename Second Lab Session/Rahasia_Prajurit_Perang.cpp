#include <bits/stdc++.h>
using namespace std;

string valueAfterColon(const string &line) {
    size_t idx = line.find(':');
    if (idx == string::npos) {
        return "";
    }
    if (idx + 2 <= line.size()) {
        return line.substr(idx + 2);
    }
    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    unordered_map<string, pair<int, string>> dataPrajurit;
    dataPrajurit.reserve(static_cast<size_t>(n) * 2);

    for (int i = 0; i < n; ++i) {
        string barisNama, barisUsia, barisAsal;
        getline(cin, barisNama);
        getline(cin, barisUsia);
        getline(cin, barisAsal);

        string nama = valueAfterColon(barisNama);
        int usia = stoi(valueAfterColon(barisUsia));
        string asal = valueAfterColon(barisAsal);

        dataPrajurit[nama] = {usia, asal};
    }

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < q; ++i) {
        string namaCari;
        getline(cin, namaCari);

        const auto &data = dataPrajurit[namaCari];
        cout << "Usia: " << data.first << '\n';
        cout << "Asal: " << data.second << '\n';
    }

    return 0;
}
