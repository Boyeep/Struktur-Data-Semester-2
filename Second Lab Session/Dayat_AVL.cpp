#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int height;
    Node *left;
    Node *right;

    explicit Node(int key) : key(key), height(1), left(nullptr), right(nullptr) {}
};

int getHeight(Node *p) {
    return p ? p->height : 0;
}

void updateHeight(Node *p) {
    if (p) {
        p->height = max(getHeight(p->left), getHeight(p->right)) + 1;
    }
}

int getBalance(Node *p) {
    return p ? getHeight(p->left) - getHeight(p->right) : 0;
}

Node *rotateRight(Node *p) {
    Node *q = p->left;
    Node *mid = q->right;

    q->right = p;
    p->left = mid;

    updateHeight(p);
    updateHeight(q);
    return q;
}

Node *rotateLeft(Node *p) {
    Node *q = p->right;
    Node *mid = q->left;

    q->left = p;
    p->right = mid;

    updateHeight(p);
    updateHeight(q);
    return q;
}

Node *insertAVL(Node *root, int val) {
    if (!root) {
        return new Node(val);
    }

    if (val < root->key) {
        root->left = insertAVL(root->left, val);
    } else if (val > root->key) {
        root->right = insertAVL(root->right, val);
    } else {
        return root;
    }

    updateHeight(root);
    int beda = getBalance(root);

    if (beda > 1 && val < root->left->key) {
        return rotateRight(root);
    }

    if (beda < -1 && val > root->right->key) {
        return rotateLeft(root);
    }

    if (beda > 1 && val > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (beda < -1 && val < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void collectVerticalSums(Node *root, int col, unordered_map<int, long long> &sumKolom) {
    if (!root) {
        return;
    }

    sumKolom[col] += root->key;
    collectVerticalSums(root->left, col - 1, sumKolom);
    collectVerticalSums(root->right, col + 1, sumKolom);
}

long long getPassword(Node *root) {
    unordered_map<int, long long> sumKolom;
    collectVerticalSums(root, 0, sumKolom);

    long long pass = 0;
    for (const auto &it : sumKolom) {
        pass += it.second * it.second;
    }
    return pass;
}

bool isNumber(const string &teks) {
    return !teks.empty() && all_of(teks.begin(), teks.end(), [](unsigned char ch) { return isdigit(ch); });
}

void processCommand(const string &cmd, istream &in, Node *&root) {
    if (cmd == "Insert") {
        int num;
        in >> num;
        root = insertAVL(root, num);
    } else if (cmd == "Password") {
        cout << getPassword(root) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node *root = nullptr;
    string awal;

    if (!(cin >> awal)) {
        return 0;
    }

    if (isNumber(awal)) {
        int banyak = stoi(awal);
        for (int i = 0; i < banyak; ++i) {
            string cmd;
            cin >> cmd;
            processCommand(cmd, cin, root);
        }
    } else {
        processCommand(awal, cin, root);
        string cmd;
        while (cin >> cmd) {
            processCommand(cmd, cin, root);
        }
    }

    return 0;
}
