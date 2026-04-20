#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // set: data unik dan otomatis terurut
    set<int> angka;
    angka.insert(5);
    angka.insert(2);
    angka.insert(5);

    // multiset: data boleh duplikat dan tetap terurut
    multiset<int> banyakAngka;
    banyakAngka.insert(7);
    banyakAngka.insert(7);
    banyakAngka.insert(3);

    // map: key -> value, key terurut
    map<string, int> nilai;
    nilai["Andi"] = 90;
    nilai["Budi"] = 85;

    // unordered_map: key -> value, tidak terurut, lookup cepat
    unordered_map<string, int> frekuensi;
    vector<string> kata = {"apel", "jeruk", "apel", "mangga"};
    for (const string &item : kata) {
        ++frekuensi[item];
    }

    // Cek ada atau tidak di set/map
    cout << (angka.count(2) ? "2 ada\n" : "2 tidak ada\n");
    cout << (nilai.count("Andi") ? "Andi ada\n" : "Andi tidak ada\n");

    // Ambil elemen terkecil/terbesar di set
    if (!angka.empty()) {
        cout << "min set = " << *angka.begin() << '\n';
        cout << "max set = " << *prev(angka.end()) << '\n';
    }

    // Iterasi map
    for (const auto &entry : nilai) {
        cout << entry.first << " -> " << entry.second << '\n';
    }

    // Iterasi unordered_map
    for (const auto &entry : frekuensi) {
        cout << entry.first << " muncul " << entry.second << " kali\n";
    }

    // Hapus data
    angka.erase(5);
    banyakAngka.erase(banyakAngka.find(7)); // hapus satu buah 7
    nilai.erase("Budi");
    frekuensi.erase("mangga");

    return 0;
}
