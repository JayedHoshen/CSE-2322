/*
    CSE 2522        : Data Structure Sessional
    Lab report-02.1 : Binary Search Tree (Insertion, Find successor, Traverse, Deletion) 
    Student_id      : 2204076
    Student_name    : Jayed hoshen
    Section         : B

---------->> Table of Content <<----------
00) Create a node
01) insert a node
02) find first
03) find successor
04) traverse in-order
05) Main Function
*/

#include<iostream>
using namespace std;

// 00) Create a node
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node* parent;

    Node(){}
    Node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class myTree_2204076{
public:
    Node* root;

    myTree_2204076() { root = nullptr; }
    myTree_2204076(int val) { root = new Node(val);}

    // 01) insert a node
    void insert_076(int val) { root = insertHelper_076(root,val,nullptr);}
    Node* insertHelper_076(Node* root, int val, Node* parent){
        if(root == nullptr){
            Node* newNode = new Node(val);
            newNode->parent = parent;
            return newNode;
        }
        if(root->data > val) root->left = insertHelper_076(root->left, val,root);
        else root->right = insertHelper_076(root->right, val,root);
        return root;
    }

    // 02) find first
    Node* find_first_076(Node* root){
        while(root->left != nullptr){
            root = root->left;
        }
        return root;
    }

    // 03) find successor
    void find_successor_076(int key){
        Node* current = root;
        Node* successor = nullptr;
        while(current != nullptr && current->data != key){
            if(current->data > key) current = current->left;
            else if(current->data < key) current = current->right;
        }        
        if(current == nullptr || current->data != key){
            cout << key << " is not present in this tree." << endl;
            return;
        }
        if(current->right != nullptr) successor = find_first_076(current->right);
        else{
            while(current->parent != nullptr && current->parent->right == current){
                current = current->parent;
                if(current->parent != nullptr && current->parent->right != current){
                    successor = current->parent;
                    break;
                }
            }
        }
        if(successor != nullptr) cout<<key<<" Successor is : "<<successor->data<<endl;
        else cout<<key<<" does not have a successor."<<endl;
    }

    // 04) traverse in-order
    void traverse_076(){
        inorder_076(root);
        cout << endl;
    }
    void inorder_076(Node* root){
        if(root == nullptr) return;
        inorder_076(root->left);
        cout << root->data << " ";
        inorder_076(root->right);
    }
};

// *********** Main Function Start **********
int main()
{
    myTree_2204076 obj;

    cout << "Enter number of node = ";
    int tc; cin >> tc;
    while(tc--){
        cout << "Enter a value = ";
        int x; cin >> x;
        obj.insert_076(x);
    }
    
    obj.traverse_076();

    cout<<"Enter a data for which you want to find Successor = ";
    int val; cin >> val;
    obj.find_successor_076(val);

    return 0;
}