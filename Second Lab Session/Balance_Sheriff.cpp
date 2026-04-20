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

Node *insertAVL(Node *root, int val, bool &pernahMiring) {
    if (!root) {
        return new Node(val);
    }

    if (val < root->key) {
        root->left = insertAVL(root->left, val, pernahMiring);
    } else if (val > root->key) {
        root->right = insertAVL(root->right, val, pernahMiring);
    } else {
        return root;
    }

    updateHeight(root);
    int beda = getBalance(root);

    if (abs(beda) > 1) {
        pernahMiring = true;
    }

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

void inorder(Node *root, vector<int> &hasil) {
    if (!root) {
        return;
    }

    inorder(root->left, hasil);
    hasil.push_back(root->key);
    inorder(root->right, hasil);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string nama;
    while (getline(cin >> ws, nama)) {
        int banyak;
        if (!(cin >> banyak)) {
            break;
        }

        Node *root = nullptr;
        bool pernahMiring = false;

        for (int i = 0; i < banyak; ++i) {
            int angka;
            cin >> angka;
            root = insertAVL(root, angka, pernahMiring);
        }

        if (pernahMiring) {
            cout << nama << " is suspicious, hang this person now!\n";
        } else {
            cout << nama << " is innocent.\n";
            vector<int> hasil;
            inorder(root, hasil);
            for (int i = 0; i < static_cast<int>(hasil.size()); ++i) {
                if (i) {
                    cout << ' ';
                }
                cout << hasil[i];
            }
            cout << '\n';
        }
    }

    return 0;
}
