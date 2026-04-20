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

Node *findMin(Node *root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

Node *findMax(Node *root) {
    while (root && root->right) {
        root = root->right;
    }
    return root;
}

Node *eraseBST(Node *root, int val) {
    if (!root) {
        return nullptr;
    }

    if (val < root->key) {
        root->left = eraseBST(root->left, val);
        return root;
    }

    if (val > root->key) {
        root->right = eraseBST(root->right, val);
        return root;
    }

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
    return root;
}

int heightInEdges(Node *root) {
    if (!root) {
        return -1;
    }

    return max(heightInEdges(root->left), heightInEdges(root->right)) + 1;
}

int countNodes(Node *root) {
    if (!root) {
        return 0;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
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

    vector<int> data = {8, 3, 10, 1, 6, 14};
    for (int x : data) {
        root = insertBST(root, x);
    }

    Node *target = findNode(root, 6);
    cout << (target ? "ketemu" : "tidak") << '\n';

    vector<int> urut;
    inorder(root, urut);
    for (int x : urut) {
        cout << x << ' ';
    }
    cout << '\n';

    root = eraseBST(root, 3);
    cout << heightInEdges(root) << '\n';
    */

    destroyTree(root);
    return 0;
}
