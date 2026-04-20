#include <bits/stdc++.h>
using namespace std;

struct Record {
    int age;
    string origin;
};

string valueAfterColon(const string &line) {
    size_t pos = line.find(':');
    if (pos == string::npos) {
        return "";
    }

    size_t start = pos + 1;
    while (start < line.size() && line[start] == ' ') {
        ++start;
    }
    return line.substr(start);
}

bool hasRecord(const unordered_map<string, Record> &data, const string &name) {
    return data.find(name) != data.end();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    POLA 1: frequency counter

    int n;
    cin >> n;

    unordered_map<string, int> freq;
    freq.reserve(static_cast<size_t>(n) * 2);

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        ++freq[word];
    }

    cout << freq["apel"] << '\n';
    */

    /*
    POLA 2: nama -> record

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    unordered_map<string, Record> data;
    data.reserve(static_cast<size_t>(n) * 2);

    for (int i = 0; i < n; ++i) {
        string lineName, lineAge, lineOrigin;
        getline(cin, lineName);
        getline(cin, lineAge);
        getline(cin, lineOrigin);

        string name = valueAfterColon(lineName);
        int age = stoi(valueAfterColon(lineAge));
        string origin = valueAfterColon(lineOrigin);

        data[name] = {age, origin};
    }

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (q--) {
        string name;
        getline(cin, name);

        if (!hasRecord(data, name)) {
            cout << "Data tidak ditemukan\n";
            continue;
        }

        const Record &person = data[name];
        cout << "Usia: " << person.age << '\n';
        cout << "Asal: " << person.origin << '\n';
    }
    */

    /*
    POLA 3: update / erase / cek ada

    unordered_map<string, Record> data;
    data["Andi"] = {19, "Surabaya"};
    data["Budi"] = {20, "Malang"};

    if (hasRecord(data, "Andi")) {
        data["Andi"].age = 21;
    }

    data.erase("Budi");
    */

    return 0;
}
