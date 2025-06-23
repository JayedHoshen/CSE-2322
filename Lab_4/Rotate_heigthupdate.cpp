/*
Name:Atiur Rahaman
Id:2204067
Section:B
*/

/*
Implement single rotations (Left-Rotate and Right-Rotate) on a binary search tree (BST).

After every rotation, correctly recompute and store the height of every node.

Print each node’s key together with its updated height (use an in-order traversal).
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        height = 1; 
        left = right = nullptr;
    }
};


int getHeight(Node* node) {
    if (!node) return 0;
    return node->height;
}


void updateHeight(Node* node) {
    if (node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

// Right rotate 
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x; 
}

// Left rotate 
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Insert in BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    updateHeight(root);
    return root;
}

// In-order traversal
void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << "Key: " << root->key << ", Height: " << root->height << endl;
    inOrder(root->right);
}


int main() {
    Node* root = nullptr;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10); // Right Rotation candidate
    cout <<endl<< "Original BST (In-Order with Heights):"<<endl;
    inOrder(root);

    //Right Rotation on root
    root = rightRotate(root);
    cout << "\nAfter Right Rotation (on node 30):\n";
    inOrder(root);

    // Insert nodes for Left Rotation
    root = insert(root, 40);
    root = insert(root, 50);

    cout <<endl<<"Before Left Rotation (In-Order with Heights):"<<endl;
    inOrder(root);

    //Left Rotation on node 20->right (node 40)
    root->right = leftRotate(root->right);
    updateHeight(root);

    cout << "\nAfter Left Rotation (on node 40):\n";
    inOrder(root);

    return 0;
}
