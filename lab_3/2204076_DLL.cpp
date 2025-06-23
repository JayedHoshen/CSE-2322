/*

Name    : Jayed Hoshen
Id      : 2204076
Section : B

    1) Write a program to create a DLL with n nodes. Each node should store an integer. 
    2) Traverse and print the list from: i) Head to Tail, ii) Tail to Head
    3) Write a function to reverse a DLL and print the list after reversal.
    4) Write a function to count the number of nodes in the DLL.
    5) Implement a function to search for a value and return its position (index).
    6) Find a node with a given value and update it with a new value.
    7) Use forward and backward traversal to check if the list is a palindrome.

*/

#include <bits/stdc++.h>
using namespace std;

// Create a node
class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    void createList(int n) {
        for (int i = 0; i < n; ++i) {
            int val;
            cout << "Enter value for node " << i + 1 << " = ";
            cin >> val;
            insertAtEnd(val);
        }
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node *newNode = new Node(val);
        if(head == nullptr) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Traverse from head to tail
    void displayForward() {
        cout << "Doubly Linked List (Head to Tail) = ";
        Node *temp = head;
        while (temp) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Traverse from tail to head
    void displayBackward() {
        cout << "Doubly Linked List (Tail to Head) = ";
        Node *temp = tail;
        while (temp) {
            cout << temp->data << "->";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    // Reverse the Doubly LinkedList
    void reverseList() {
        Node *current = head;
        Node *temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr)  head = temp->prev;
    }

    // Count nodes
    int countNodes() {
        int count = 0;
        Node *temp = head;
        while (temp) {
            ++count;
            temp = temp->next;
        }
        return count;
    }

    // Search value and return index (0-based)
    int searchValue(int val) {
        int index = 0;
        Node *temp = head;
        while (temp) {
            if (temp->data == val) return index;
            index++;
            temp = temp->next;
        }
        return -1;
    }

    // Update a node with given old value to new value
    bool updateValue(int oldVal, int newVal) {
        Node *temp = head;
        while (temp) {
            if (temp->data == oldVal) {
                temp->data = newVal;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Check if the LinkedList is a palindrome
    bool isPalindrome() {
        Node *left = head;
        if (left == NULL) return true;
        Node *right = left;
        while (right->next != NULL) right = right->next;
        while (left != right && right != left->prev) {
            if(left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    
    cout << "Enter number of nodes = ";
    int n; cin >> n;
    dll.createList(n);

    cout << endl;
    dll.displayForward();
    dll.displayBackward();
    cout << endl;

    // Reverse DLL
    dll.reverseList();
    cout << "After reversing ";
    dll.displayForward();
    cout << endl;

    // Count nodes
    cout << "Total nodes = " << dll.countNodes() << endl;

    // Search    
    cout << "\nEnter value to search = ";
    int value; cin >> value;
    int index = dll.searchValue(value);
    if (index != -1) cout << "Value found at index " << index << endl;
    else cout << "Value not found\n";

    // Update
    int oldVal, newVal;
    cout << "\nEnter value to update = ";
    cin >> oldVal;
    cout << "Enter new value = ";
    cin >> newVal;
    if (dll.updateValue(oldVal, newVal)) cout << "Value updated successfully" << endl;
    else cout << "Value not found to update" << endl;
    dll.displayForward();

    // Check palindrome
    if (dll.isPalindrome()) cout << "\nThis list is a palindrome\n";
    else cout << "\nThis list is NOT a palindrome\n";
    cout << endl;

    return 0;
}