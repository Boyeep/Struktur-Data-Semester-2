#include <iostream>
#include <vector>
using namespace std;

void WRITE(string *Kata, vector<string> *Kalimat) {
    Kalimat->push_back(*Kata);
}

void BACKSPACE(vector<string> *Kalimat) {
    if(!Kalimat->empty()) {
    Kalimat->pop_back();
    }
}

void PRINTf(vector<string> *Kalimat) {
    for(auto it : *Kalimat) {
        cout << it;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> Kalimat;

    string Perintah, Kata;

    while(cin >> Perintah) {

    if(Perintah == "WRITE") {
        cin >> Kata;
        WRITE(&Kata, &Kalimat);
    }

    else if(Perintah == "BACKSPACE") {
        BACKSPACE(&Kalimat);
    }

    else if(Perintah == "PRINT") {
        PRINTf(&Kalimat);

        return 0;
    }
}
}