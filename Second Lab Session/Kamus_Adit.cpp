#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, int> frek;
    int isiKamus1 = 0;
    int isiKamus2 = 0;

    for (int i = 0; i < n; ++i) {
        string kata;
        cin >> kata;

        int &kali = frek[kata];
        if (kali == 0) {
            ++isiKamus1;
            cout << kata << " masuk Kamus 1!\n";
        } else if (kali == 1) {
            ++isiKamus2;
            cout << kata << " masuk Kamus 2!\n";
        } else {
            cout << kata << " tidak bisa masuk Kamus!\n";
        }
        ++kali;
    }

    cout << "Kamus 1 berisi " << isiKamus1 << " kata\n";
    cout << "Kamus 2 berisi " << isiKamus2 << " kata\n";

    return 0;
}
