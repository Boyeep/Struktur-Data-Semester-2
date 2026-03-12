#include <bits/stdc++.h>
using namespace std;

void UbahUkuran(int *&arr, int &kapasitas, int ukuranBaru) {
    int *baru = new int[ukuranBaru];

    for (int i = 0; i < kapasitas; i++) {
        baru[i] = arr[i];
    }

    delete[] arr;
    arr = baru;
    kapasitas = ukuranBaru;
}

void AddBack(int *&arr, int &ukuran, int &kapasitas, int x) {
    if (ukuran == kapasitas) {
        UbahUkuran(arr, kapasitas, kapasitas * 2);
    }

    arr[ukuran] = x;
    ukuran++;
}

void AddAll(int *arr, int ukuran, int x) {
    for (int i = 0; i < ukuran; i++) {
        arr[i] += x;
    }
}

void DelBack(int &ukuran) {
    if (ukuran == 0) {
        cout << "kosong woe" << '\n';
    } else {
        ukuran--;
    }
}

void Printf(int *arr, int ukuran) {
    if (ukuran == 0) {
        cout << "gaada isinya :(" << '\n';
        return;
    }

    for (int i = 0; i < ukuran; i++) {
        cout << arr[i];
        if (i != ukuran - 1) {
            cout << ' ';
        }
    }
    cout << '\n';
}

void InsertPosisi(int *&arr, int &ukuran, int &kapasitas, int y, int x) {
    if (ukuran == kapasitas) {
        UbahUkuran(arr, kapasitas, kapasitas * 2);
    }

    if (y < 0) {
        y = 0;
    }
    if (y > ukuran) {
        y = ukuran;
    }

    for (int i = ukuran; i > y; i--) {
        arr[i] = arr[i - 1];
    }

    arr[y] = x;
    ukuran++;
}

int main() {
    int t;
    cin >> t;

    int kapasitas = 1;
    int ukuran = 0;
    int *arr = new int[kapasitas];

    for (int i = 0; i < t; i++) {
        int Operation;
        cin >> Operation;

        if (Operation == 1) {
            int x;
            cin >> x;
            AddBack(arr, ukuran, kapasitas, x);
        } else if (Operation == 2) {
            int x;
            cin >> x;
            AddAll(arr, ukuran, x);
        } else if (Operation == 3) {
            DelBack(ukuran);
        } else if (Operation == 4) {
            Printf(arr, ukuran);
        } else if (Operation == 5) {
            int y, x;
            cin >> y >> x;
            InsertPosisi(arr, ukuran, kapasitas, y, x);
        }
    }

    delete[] arr;
    return 0;
}
