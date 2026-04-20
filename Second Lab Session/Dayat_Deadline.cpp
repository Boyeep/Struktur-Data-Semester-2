#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int size;
    Node *left;
    Node *right;

    explicit Node(int key) : key(key), size(1), left(nullptr), right(nullptr) {}
};

int getSize(Node *p) {
    return p ? p->size : 0;
}

void updateSize(Node *p) {
    if (p) {
        p->size = getSize(p->left) + getSize(p->right) + 1;
    }
}

Node *insertBST(Node *root, int val) {
    if (!root) {
        return new Node(val);
    }

    if (val < root->key) {
        root->left = insertBST(root->left, val);
    } else if (val > root->key) {
        root->right = insertBST(root->right, val);
    }

    updateSize(root);
    return root;
}

pair<Node *, Node *> findWithParent(Node *root, int val) {
    Node *par = nullptr;
    Node *cur = root;

    while (cur) {
        if (val == cur->key) {
            return {cur, par};
        }

        par = cur;
        if (val < cur->key) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    return {nullptr, par};
}

int getRank(Node *root, int val) {
    int urutan = 0;
    Node *cur = root;

    while (cur) {
        if (val < cur->key) {
            cur = cur->left;
        } else if (val > cur->key) {
            urutan += getSize(cur->left) + 1;
            cur = cur->right;
        } else {
            urutan += getSize(cur->left) + 1;
            return urutan;
        }
    }

    return urutan;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    Node *root = nullptr;

    for (int i = 0; i < q; ++i) {
        string cmd;
        int num;
        cin >> cmd >> num;

        if (cmd == "Insert") {
            root = insertBST(root, num);
        } else if (cmd == "Parent") {
            pair<Node *, Node *> res = findWithParent(root, num);
            Node *anak = res.first;
            Node *par = res.second;
            if (!anak || !par) {
                cout << "Orphanage, here it comes\n";
            } else {
                cout << "Child of " << par->key << '\n';
            }
        } else if (cmd == "Order") {
            cout << "Order : " << getRank(root, num) << '\n';
        }
    }

    return 0;
}
