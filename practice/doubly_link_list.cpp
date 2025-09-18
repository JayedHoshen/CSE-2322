/*
    Working with doubly linked list.
    1) insert at tail
    2) insert at pos
    3) insert at head
    4) delete tail
    5) delete pos
    6) delete head
    7) input linked list
    8) count node
    9) find a value
    10) print reverse/normal order
    11) reverse linked list
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// 1) insert at tail O(1)
void insert_at_tail(Node* &head, Node* &tail, int v) {
    Node* newNode = new Node(v);
    if(tail == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}

// 2) insert at position O(n)
void insert_at_pos(Node* head, int pos, int v) {
    Node* newNode = new Node(v);

    Node* tmp = head;
    for(int i = 1; i < pos; i++) tmp = tmp->next;
    if(tmp->next == NULL) {
        cout << "Invalid, it is a tail position\n";
        return;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = tmp;
}

// 3) insert at head O(1) 
void insert_at_head(Node* &head, Node* &tail, int v) {
    Node* newNode = new Node(v);
    if(head == NULL) {
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// 4) delete tail O(1) 
void delete_tail(Node* &head, Node* &tail){
    Node* deleteNode = tail;
    tail = tail->prev;
    delete deleteNode;    
    if(tail == NULL) {
        head = NULL;
        return;
    }
    tail->next = NULL;
}

// 5) delete pos O(n)
void delete_pos(Node* head, int pos) {
    Node* tmp = head;
    for(int i = 1; i < pos; i++) tmp = tmp->next;
    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    tmp->next->prev = tmp;
    delete deleteNode;
}

// 6) delete head O(1)
void delete_head(Node* &head, Node* &tail){
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
    if(head == NULL) {
        tail = NULL;
        return;
    }
    head->prev = NULL;
}

// 7) input linked list O(n)
void inputList(Node* &head, Node* &tail) {
    int val; 
    while(true) {
        cin >> val;
        if(val == -1) break;
        insert_at_tail(head, tail, val);
    }
}

// 8) count node O(n)
int countNode(Node* head) {
    Node* tmp = head;
    int cnt = 0;
    while(tmp != NULL) {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

// 9) Find a Node O(n)
void findNode(Node* head, int val){
    Node* tmp = head;
    bool flag = false;
    while(tmp != NULL) {
        if(tmp->val == val) flag = true;
        tmp = tmp->next;
    }
    if(flag) cout << "Found\n";
    else cout << "Not found\n";
}

// 10.1) print normal order O(n)
void printNormal(Node* head) {
    Node* tmp = head;
    cout << "Normal list = ";
    while(tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// 10.2) print reverse order O(n)
void printReverse(Node* tail) {
    Node* tmp = tail;
    cout << "Reverse list = ";
    while(tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

// 11) reverse linked list
void reverseList(Node* head, Node* tail) {
    Node* i = head;
    Node* j = tail;
    while(i != j && i->next != j) {
        int tmp = i->val;
        i->val = j->val;
        j->val = tmp;
        i = i->next; 
        j = j->prev;
    }
    int tmp = i->val;
    i->val = j->val;
    j->val = tmp;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    // insert mechanism
    // int pos = 1, val = 100; 
    // if(pos > countNode(head)) cout << "Invalid index\n";
    // else if(pos == 0) insert_at_head(head, tail, val);
    // else if(pos == countNode(head)) insert_at_tail(head, tail, val);
    // else insert_at_pos(head, pos, val);

    // delete mechanism
    // int pos = 3;
    // if(pos >= countNode(head)) cout << "Invalid index\n";
    // else if(pos == 0) delete_head(head, tail);
    // else if(pos == countNode(head)-1) delete_tail(head, tail);
    // else  delete_pos(head, pos);
    
    inputList(head, tail);
    printNormal(head);
    // printReverse(tail);
    reverseList(head, tail);
    printNormal(head);

    return 0;
}