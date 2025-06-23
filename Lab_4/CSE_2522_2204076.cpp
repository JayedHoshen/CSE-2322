#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int val){
        this->key = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree_2204076 {
public:
    Node* root;

    BinaryTree_2204076() : root(nullptr) {}

    Node* leftRotate(Node* x) {
        if (!x || !x->right) return x;

        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        return y;
    }

    void inorder(Node* node) {
        if (!node) return;

        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }

    void printInorder() {
        inorder(root);
        cout << endl;
    }
};

int height(Node* root) {
    if(!root) return 0;
    return 1+max(height(root->left), height(root->right));
}

int main()
{
    BinaryTree_2204076 tree;

    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(5);
    tree.root->left->left = new Node(3);
    tree.root->left->right= new Node(4);

    cout << "Inorder before left rotation: ";
    tree.printInorder();
    cout << "Height = " << height(tree.root) << endl;

    tree.root = tree.leftRotate(tree.root);
    cout << "Inorder after left rotation: ";
    tree.printInorder();
    cout << "Height = " << height(tree.root) << endl;

    return 0;
}