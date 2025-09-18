/*
    Working with singly linked list.
    1) insert at tail
    2) insert at pos
    3) insert at head
    4) delete pos
    5) delete head
    6) input linked list
    7) count node
    8) find a value
    9) print reverse order
    10) reverse linked list
    11) sort linked list
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* next;

        Node(int val) {
            this->val = val;
            this->next = NULL;
        }
};

// 01) Insert at tail O(1)
void insert_at_tail(Node* &head, Node* &tail, int v) {
    Node* newNode = new Node(v);

    if(head == NULL) {
        head = newNode;
        tail = newNode;
        cout << "\nInserted at tail\n";
        return;
    }
    tail->next = newNode;
    tail = newNode;
    cout << "\nInserted at tail\n";
}

// 02) Insert at position with tail O(n)
void insert_at_pos(Node* head, int pos, int v) {
    Node* newNode = new Node(v);

    Node* tmp = head;
    for(int i = 1; i < pos; i++) {
        tmp = tmp->next;
        if(tmp == NULL) {
            cout << "Invalid position\n";
            return;
        }
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    cout << "\nInserted at " << pos << " position\n";
}

// 03) Insert at head O(1)
void insert_at_head(Node* &head, Node* &tail, int v) {
    Node* newNode = new Node(v);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        cout << "\nInserted at head\n";
        return;
    }
    newNode->next = head;
    head = newNode;
    cout << "\nInserted at head\n";
}

// 04) delete pos O(n)
void delete_pos(Node* head, int pos){
    Node* tmp = head;
    for(int i = 1; i < pos; i++) {
        tmp = tmp->next;
        if(tmp == NULL) { // size er soman hole
            cout << "Invalid index\n";
            return ;
        }
    }
    if(tmp->next == NULL) { // size er theke boro hole
        cout << "Invalid index\n";
        return ;
    }
    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
    cout << "\nDeleted at " << pos << " position\n";
}

// 05) delete head O(1)
void delete_head(Node* &head){
    if(head == NULL) {
        cout << "Head is NULL\n";
        return;
    }
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
    cout << "\nDeleted at head\n";
}

// 06) Input linked list
void inputList(Node* &head, Node* &tail) {
    int val; 
    while(true) {
        cin >> val;
        if(val == -1) break;
        insert_at_tail(head, tail, val);
    }
}

// 07) Count Node O(n)
int countNode(Node* head){
    int cnt = 0;
    Node* tmp = head;
    while(tmp != NULL) {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

// 08) Find a Node O(n)
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

// 09) Print Reverse order (recursive)
void printReverse(Node* head) {
    if(head == NULL) return;
    printReverse(head->next);
    cout << head->val << " ";
}

// 10) Reverse linked list
void reverseList(Node* &head, Node* cur) {
    if(cur->next == NULL) {
        head = cur;
        return;
    }
    reverseList(head, cur->next);
    cur->next->next = cur;
    cur->next = NULL;
}

// 11) Sort linked list
void sortList(Node* head) {
    for(Node* i = head; i->next != NULL; i = i->next) {
        for(Node* j = i->next; j != NULL; j = j->next) {
            if(i->val > j->val) {
                int tmp = i->val;
                i->val = j->val;
                j->val = tmp;
            }
        }
    }
}

// Print linked list
void printList(Node* head) {
    cout << "Linked list is = ";
    Node* tmp = head;
    while(tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    
    // inputList(head, tail);
    
    // insert_at_head(head, tail, 50);
    // printList(head);

    // insert_at_tail(head, tail, 10);    
    // printList(head);

    // insert_at_pos(head, 2, 20);
    // printList(head);

    // delete_pos(head, 2);
    // printList(head);

    // delete_head(head);
    // printList(head);
    
    // printList(head);
    // printReverse(head);

    // sortList(head); cout << endl;
    // printList(head);
    
    // reverseList(head, head);
    // printList(head);

    return 0;
}