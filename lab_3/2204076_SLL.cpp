/*

Name: Jayed Hoshen
Id:2204076
Section: B

Problems: 
    1) Write a program to create a singly linked list and display its elements.
    2) Implement functions to insert a node at the beginning and end of the linked list.
    3) Write a function to delete the first occurrence of a given value in a linked list.
    4) Write a function to count the total number of nodes in a linked list.
    5) Write a function to search for an element in a linked list.

Extra:
    6) Write a function to reverse a singly linked list.
    7) Given a sorted linked list, remove all duplicates so that each element appears only once.

*/

#include <bits/stdc++.h>
using namespace std;

// 01) Create a singly linked list 
class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this -> val = val;
        this -> next = NULL;
    }
};

class linked_list {
    public:
        // 01) Print a link list
        void print(Node* head) {
            Node* tmp = head;
            cout << "My list = ";
            while(tmp != NULL) {
                cout << tmp->val << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }

        // 02) insert at head
        void insert_at_head(Node* &head, int v) {
            Node* newNode = new Node(v);
            newNode->next = head;
            head = newNode;
        }

        // 02) insert at tail
        void insert_at_tail(Node* &head, Node* &tail, int v) {
            Node *newNode = new Node(v);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
                return;
            }
            tail->next = newNode;
            tail = newNode;
        }

        // 03) Delete first occurrence of a value
        void delete_head(Node* &head, int val) {
            if(head == NULL) return;

            if(head->val == val) {
                Node* tmp = head;
                head = head->next;
                delete tmp;
                return;
            }

            Node* tmp = head;
            while(tmp->next != NULL && tmp->next->val != val) tmp = tmp->next;

            if(tmp->next == NULL) {
                cout << "Value " << val << " not found in this list.\n";
                return;
            }

            Node* deleteNode = tmp->next;
            tmp->next = deleteNode->next;
            delete deleteNode;
            cout << "Successfully deleted " << val << endl;
        }        

        // 04) count number of node
        int cnt = 0;
        void count_node(Node* head) {
            Node* tmp = head;
            while(tmp != NULL) {
                tmp = tmp->next;
                cnt++;
            }
            cout << "Total number of node = " << cnt << endl;
        }

        // 05) Search a node
        bool search(Node* head, int val) {
            Node* tmp = head;
            while(tmp != NULL) {
                if(tmp->val == val) return true;
                tmp = tmp->next;
            }
            return false;
        }        

        // 06) Reverse a link list
        void reverse(Node* &head, Node* cur) {
            if(cur->next == NULL) {
                head = cur;
                return;
            }
            reverse(head, cur->next);
            cur->next->next = cur;
            cur->next = NULL;
        }

        // Sorting a linked list
        void LLSort(Node* &head) {
            for(Node* i = head; i != NULL; i = i->next) {
                Node* mn = i;
                for(Node* j = i->next; j != NULL; j = j->next) {
                    if(j->val < mn->val) mn = j;
                }
                if(mn != i) {
                    int tmp = i->val;
                    i->val = mn->val;
                    mn->val = tmp;
                }
            }
        }

        // 07) Remove duplicates value
        void removeDup(Node* &head) {
            Node* cur = head;
            while(cur != NULL && cur->next != NULL) {
                if(cur->val == cur->next->val) {
                    Node* tmp = cur->next;
                    cur->next = tmp->next;
                    delete tmp;
                }
                else cur = cur->next;
            }
        }
};

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    linked_list tc;

    // initially input value / create link list
    cout << "Enter a list (-1 to terminated) = ";
    int val;
    while(true) {
        cin >> val;
        if(val == -1) break;
        tc.insert_at_tail(head, tail, val);
    }
    tc.print(head);

    cout << "\nEnter search value = ";
    int vl; cin >> vl;
    if(tc.search(head, vl)) cout << "Value " << vl << " found in the list\n";
    else cout << "Value " << vl << " not found in the list\n";

    cout << "\ninsert at head ------\n";
    cout << "Enter your value = ";
    int h; cin >> h;
    tc.insert_at_head(head, h);
    tc.print(head);

    cout << "\ninsert at tail ------\n";
    cout << "Enter your value = ";
    int t; cin >> t;
    tc.insert_at_tail(head, tail, t);
    tc.print(head);

    cout << endl;
    tc.count_node(head);

    cout << "\nEnter a deleted value = ";
    int value; cin >> value;
    tc.delete_head(head, value);
    tc.print(head);

    cout << "\nReverse link list\n";
    tc.reverse(head, head);
    tc.print(head);

    cout << "\nSorted linked list\n";
    tc.LLSort(head);
    tc.print(head);

    tc.removeDup(head);
    cout << "\nAfter remove duplicate value\n";
    tc.print(head);

    return 0;
}