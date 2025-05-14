#include <bits/stdc++.h>
using namespace std;

// Create a singly linked list 
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
        // Print a link list
        void print(Node* head) {
            Node* tmp = head;
            cout << "My list = ";
            while(tmp != NULL) {
                cout << tmp->val << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }

        // count node
        int cnt = 0;
        void count_node(Node* head) {
            Node* tmp = head;
            while(tmp != NULL) {
                tmp = tmp->next;
                cnt++;
            }
            cout << "Total node = " << cnt << endl;
        }
        
        // insert at head
        void insert_at_head(Node* &head, int v) {
            Node* newNode = new Node(v);
            newNode->next = head;
            head = newNode;
            cout << endl << endl << "Inserted at head" << endl;
        }

        // insert at tail
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

        // delete head 
        void delete_head(Node* &head) {
            Node* deleteNode = head;
            head = head->next;
            delete deleteNode;
            cout << "Deleted head" << endl;
        }

        // Reverse a link list
        void reverse(Node* &head, Node* cur) {
            if(cur->next == NULL) {
                head = cur;
                return;
            }
            reverse(head, cur->next);
            cur->next->next = cur;
            cur->next = NULL;
        }
};

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    linked_list tc;

    // input value 
    cout << "Enter a list (-1 to terminated) = ";
    int val;
    while(true) {
        cin >> val;
        if(val == -1) break;
        tc.insert_at_tail(head, tail, val);
    }
    tc.print(head);

    while(1) {
        cout << "Option 1: Insert head" << endl;
        cout << "Option 2: Insert tail" << endl;
        cout << "Option 3: Delete head" << endl;
        cout << "Option 4: Count node" << endl;
        cout << "Option 5: Print link list" << endl;
        cout << "Option 6: Reverse link list" << endl;
        cout << "Option 7: Terminated" << endl;

        int op;
        cin >> op;

        
    }

    cout << "insert at head ------\n";
    cout << "Enter your value = ";
    int h; cin >> h;
    tc.insert_at_head(head, h);
    tc.print(head);

    cout << "insert at tail ------\n";
    cout << "Enter your value = ";
    int t; cin >> t;
    tc.insert_at_tail(head, tail, t);
    tc.print(head);

    tc.count_node(head);

    cout << "Before delete at head-----\n";
    tc.print(head);
    cout << "After ";
    tc.delete_head(head);
    tc.print(head);

    cout << "Reverse link list\n";
    tc.reverse(head, head);

    return 0;
}