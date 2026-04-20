#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int height;
    Node *left;
    Node *right;

    explicit Node(int key) : key(key), height(1), left(nullptr), right(nullptr) {}
};

int getHeight(Node *root) {
    return root ? root->height : 0;
}

void updateHeight(Node *root) {
    if (root) {
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
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

    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

Node *rotateLeft(Node *root) {
    Node *newRoot = root->right;
    Node *movedSubtree = newRoot->left;

    newRoot->left = root;
    root->right = movedSubtree;

    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

Node *rebalance(Node *root) {
    updateHeight(root);
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

void inorder(Node *root, vector<int> &result) {
    if (!root) {
        return;
    }

    inorder(root->left, result);
    result.push_back(root->key);
    inorder(root->right, result);
}

void preorder(Node *root, vector<int> &result) {
    if (!root) {
        return;
    }

    result.push_back(root->key);
    preorder(root->left, result);
    preorder(root->right, result);
}

void postorder(Node *root, vector<int> &result) {
    if (!root) {
        return;
    }

    postorder(root->left, result);
    postorder(root->right, result);
    result.push_back(root->key);
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
    Contoh pakai:

    vector<int> data = {30, 20, 10, 25, 40, 50};
    for (int x : data) {
        root = insertAVL(root, x);
    }

    root = eraseAVL(root, 20);

    vector<int> urut;
    inorder(root, urut);
    for (int x : urut) {
        cout << x << ' ';
    }
    cout << '\n';
    */

    destroyTree(root);
    return 0;
}
