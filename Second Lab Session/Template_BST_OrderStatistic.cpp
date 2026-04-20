#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int size;
    Node *left;
    Node *right;

    explicit Node(int key) : key(key), size(1), left(nullptr), right(nullptr) {}
};

int getSize(Node *root) {
    return root ? root->size : 0;
}

void updateSize(Node *root) {
    if (root) {
        root->size = getSize(root->left) + getSize(root->right) + 1;
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
    } else {
        return root;
    }

    updateSize(root);
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

pair<Node *, Node *> findWithParent(Node *root, int val) {
    Node *parent = nullptr;
    Node *current = root;

    while (current) {
        if (val == current->key) {
            return {current, parent};
        }

        parent = current;
        if (val < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return {nullptr, parent};
}

Node *findMin(Node *root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

Node *eraseBST(Node *root, int val) {
    if (!root) {
        return nullptr;
    }

    if (val < root->key) {
        root->left = eraseBST(root->left, val);
    } else if (val > root->key) {
        root->right = eraseBST(root->right, val);
    } else {
        if (!root->left) {
            Node *next = root->right;
            delete root;
            return next;
        }

        if (!root->right) {
            Node *next = root->left;
            delete root;
            return next;
        }

        Node *successor = findMin(root->right);
        root->key = successor->key;
        root->right = eraseBST(root->right, successor->key);
    }

    updateSize(root);
    return root;
}

int countLessThan(Node *root, int val) {
    int result = 0;

    while (root) {
        if (val <= root->key) {
            root = root->left;
        } else {
            result += getSize(root->left) + 1;
            root = root->right;
        }
    }

    return result;
}

int getRank(Node *root, int val) {
    int rank = 0;

    while (root) {
        if (val < root->key) {
            root = root->left;
        } else if (val > root->key) {
            rank += getSize(root->left) + 1;
            root = root->right;
        } else {
            rank += getSize(root->left) + 1;
            return rank;
        }
    }

    return 0;
}

Node *kthSmallest(Node *root, int k) {
    if (k <= 0 || k > getSize(root)) {
        return nullptr;
    }

    while (root) {
        int leftSize = getSize(root->left);

        if (k == leftSize + 1) {
            return root;
        }

        if (k <= leftSize) {
            root = root->left;
        } else {
            k -= leftSize + 1;
            root = root->right;
        }
    }

    return nullptr;
}

void inorder(Node *root, vector<int> &result) {
    if (!root) {
        return;
    }

    inorder(root->left, result);
    result.push_back(root->key);
    inorder(root->right, result);
}

void destroyTree(Node *root) {
    if (!root) {
        return;
    }

    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node *root = nullptr;

    /*
    Semantics:
    - getRank(root, x) -> rank 1-based jika x ada, 0 jika tidak ada.
    - countLessThan(root, x) -> banyak elemen yang < x.
    - kthSmallest(root, k) -> node ke-k terkecil, k dimulai dari 1.

    Contoh pakai:

    vector<int> data = {50, 30, 70, 20, 40, 60, 80};
    for (int x : data) {
        root = insertBST(root, x);
    }

    cout << getRank(root, 60) << '\n';          // 5
    cout << countLessThan(root, 65) << '\n';    // 5

    Node *kth = kthSmallest(root, 3);
    if (kth) {
        cout << kth->key << '\n';               // 40
    }

    root = eraseBST(root, 30);
    */

    destroyTree(root);
    return 0;
}
