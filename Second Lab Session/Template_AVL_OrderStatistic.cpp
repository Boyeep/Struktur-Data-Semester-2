#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int height;
    int size;
    Node *left;
    Node *right;

    explicit Node(int key) : key(key), height(1), size(1), left(nullptr), right(nullptr) {}
};

int getHeight(Node *root) {
    return root ? root->height : 0;
}

int getSize(Node *root) {
    return root ? root->size : 0;
}

void pull(Node *root) {
    if (root) {
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        root->size = getSize(root->left) + getSize(root->right) + 1;
    }
}

int getBalance(Node *root) {
    return root ? getHeight(root->left) - getHeight(root->right) : 0;
}

Node *rotateRight(Node *root) {
    Node *newRoot = root->left;
    Node *movedSubtree = newRoot->right;

    newRoot->right = root;
    root->left = movedSubtree;

    pull(root);
    pull(newRoot);
    return newRoot;
}

Node *rotateLeft(Node *root) {
    Node *newRoot = root->right;
    Node *movedSubtree = newRoot->left;

    newRoot->left = root;
    root->right = movedSubtree;

    pull(root);
    pull(newRoot);
    return newRoot;
}

Node *rebalance(Node *root) {
    if (!root) {
        return nullptr;
    }

    pull(root);
    int balance = getBalance(root);

    if (balance > 1) {
        if (getBalance(root->left) < 0) {
            root->left = rotateLeft(root->left);
        }
        return rotateRight(root);
    }

    if (balance < -1) {
        if (getBalance(root->right) > 0) {
            root->right = rotateRight(root->right);
        }
        return rotateLeft(root);
    }

    return root;
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

    return rebalance(root);
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

Node *findMin(Node *root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

Node *eraseAVL(Node *root, int val) {
    if (!root) {
        return nullptr;
    }

    if (val < root->key) {
        root->left = eraseAVL(root->left, val);
    } else if (val > root->key) {
        root->right = eraseAVL(root->right, val);
    } else {
        if (!root->left || !root->right) {
            Node *child = root->left ? root->left : root->right;
            delete root;
            return child;
        }

        Node *successor = findMin(root->right);
        root->key = successor->key;
        root->right = eraseAVL(root->right, successor->key);
    }

    return rebalance(root);
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

    vector<int> data = {30, 20, 10, 25, 40, 50, 35};
    for (int x : data) {
        root = insertAVL(root, x);
    }

    cout << getRank(root, 35) << '\n';
    cout << countLessThan(root, 36) << '\n';

    Node *kth = kthSmallest(root, 4);
    if (kth) {
        cout << kth->key << '\n';
    }

    root = eraseAVL(root, 20);
    */

    destroyTree(root);
    return 0;
}
