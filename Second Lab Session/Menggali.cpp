#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;

    explicit Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

Node *insertBST(Node *root, int val) {
    if (!root) {
        return new Node(val);
    }

    if (val < root->key) {
        root->left = insertBST(root->left, val);
    } else if (val > root->key) {
        root->right = insertBST(root->right, val);
    }

    return root;
}

Node *findNode(Node *root, int val) {
    while (root) {
        if (val == root->key) {
            return root;
        }

        if (val < root->key) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return nullptr;
}

int heightInEdges(Node *p) {
    if (!p) {
        return -1;
    }

    return max(heightInEdges(p->left), heightInEdges(p->right)) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Node *root = nullptr;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        root = insertBST(root, num);
    }

    int mulai;
    cin >> mulai;

    Node *titikAwal = findNode(root, mulai);
    long long tinggi = heightInEdges(titikAwal);
    cout << tinggi * tinggi * 10000LL << '\n';

    return 0;
}
