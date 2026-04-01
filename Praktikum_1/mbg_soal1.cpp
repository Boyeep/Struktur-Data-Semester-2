#include <bits/stdc++.h>
using namespace std;

struct Rak2 {
    string menu;
    size_t count;
};

struct Rack {
    vector<Rak2> rak2;
    size_t total = 0;
};

void removeRak2At(vector<Rak2>& rak2, size_t index) {
    for (size_t i = index + 1; i < rak2.size(); ++i) {
        rak2[i - 1] = rak2[i];
    }
    rak2.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    vector<Rack> raks(1);

    while (q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "new") {
            raks.push_back(Rack{});
            continue;
        }

        if (cmd == "put") {
            size_t l, y;
            string x;
            cin >> l >> x >> y;

            if (l < 1 || l > raks.size()) {
                cout << "Rak " << l << " gak ketemu\n";
                continue;
            }

            Rack& rak = raks[l - 1];
            rak.total += y;

            if (!rak.rak2.empty() && rak.rak2.back().menu == x) {
                rak.rak2.back().count += y;
            } else {
                rak.rak2.push_back({x, y});
            }

            continue;
        }

        if (cmd == "del") {
            size_t l, z;
            cin >> l >> z;

            if (l < 1 || l > raks.size() || z < 1 || z > raks[l - 1].total) {
                cout << "Rak " << l << " urutan " << z << " kosong\n";
                continue;
            }

            Rack& rak = raks[l - 1];
            size_t test = 0;

            for (size_t i = 0; i < rak.rak2.size(); ++i) {
                Rak2& rak3 = rak.rak2[i];
                if (test + rak3.count < z) {
                    test += rak3.count;
                    continue;
                }

                string removedMenu = rak3.menu;
                --rak3.count;
                --rak.total;

                if (rak3.count == 0) {
                    removeRak2At(rak.rak2, i);
                    if (i > 0 && i < rak.rak2.size() &&
                        rak.rak2[i - 1].menu == rak.rak2[i].menu) {
                        rak.rak2[i - 1].count += rak.rak2[i].count;
                        removeRak2At(rak.rak2, i);
                    }
                }

                cout << "Menu " << removedMenu << " beracun, Sisa rak: " << rak.total << '\n';
                break;
            }
        }
    }

    return 0;
}
