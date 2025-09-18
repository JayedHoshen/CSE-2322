/*
---------->> Some operation in a binary tree
1) pre-order
2) in-order
3) post-order
4) level-order
5) input binary tree
6) count number of node
7) count number of leaf node
8) maximumHeight
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// 1) pre-order traversal
void preorder(Node* root) {
    if(root == NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// 2) in-order traversal
void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// 3) post-order traversal
void postorder(Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// 4) level-order traversal
void levelorder(Node* root) {
    if(root == NULL) return;

    queue <Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* f = q.front();
        q.pop();

        cout << f->val << " ";

        if(f->right) q.push(f->right); // right level to left
        if(f->left) q.push(f->left);
    }
}

// 5) input binary tree
Node* input_tree() {
    int val; cin >> val;
    Node* root;
    if(val == -1) root = NULL;
    else root = new Node(val);

    queue <Node*> q;
    if(root) q.push(root);
    while(!q.empty()) {
        Node* p = q.front();
        q.pop();

        int l, r; cin >> l >> r;
        Node *myLeft, *myRight;
        if(l == -1) myLeft = NULL;
        else myLeft = new Node(l);
        if(r == -1) myRight = NULL;
        else myRight = new Node(r);
        p->left = myLeft;
        p->right = myRight;

        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    return root;
}

// 6) count number of node
int countNode(Node* root) {
    if(root == NULL) return 0;
    int l = countNode(root->left);
    int r = countNode(root->right);
    return (l+r+1);
}

// 7) count number of leaf node
int countLeaf(Node* root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    else {
        int l = countLeaf(root->left);
        int r = countLeaf(root->right);
        return (l+r);
    }
}

// 8) maximumHeight
int maxHeight(Node* root) {
    if(root == NULL) return 0;
    int l = maxHeight(root->left);
    int r = maxHeight(root->right);
    return max(l, r) + 1;
}

int main()
{
    // create 10 node
    // Node* root = new Node(10);Node* a = new Node(20);Node* b = new Node(30);Node* c = new Node(40);Node* d = new Node(50);Node* e = new Node(60);Node* f = new Node(70);Node* g = new Node(80);Node* h = new Node(90);Node* i = new Node(100);

    // connection node
    // root->left = a;root->right = b;a->left = c;a->right = h;c->right = e;h->right = i;b->right = d;d->left = f;d->right = g;

    Node* root = input_tree();

    // Traversal output in Binary Tree
    // cout << "Pre-order traverse = ";preorder(root);cout << endl;
    // cout << "In-order traverse = ";inorder(root);cout << endl;
    // cout << "Post-order traverse = ";postorder(root);cout << endl;
    // cout << "Level-order traverse = ";levelorder(root);cout << endl;

    // cout << "Number of node = " << countNode(root) << endl;
    // cout << "Number of leaf node = " << countLeaf(root) << endl;
    cout << "Height = " << maxHeight(root) << endl;

    return 0;
}