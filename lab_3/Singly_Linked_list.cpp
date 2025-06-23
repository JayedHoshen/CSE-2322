/*
Name:Atiur Rahaman
Id:2204067
Section:B
*/

/*
1/Write a program to create a singly linked list and display its elements.
2/Implement functions to insert a node at the beginning and end of the linked list.
3/Write a function to delete the first occurrence of a given value in a linked list.
4/Write a function to count the total number of nodes in a linked list.
5/Write a function to search for an element in a linked list.

Extra:
6.Write a function to reverse a singly linked list.
7.Given a sorted linked list, remove all duplicates so that each element appears only once.
*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    // Display list
    void display()
    {
        Node *temp = head;
        cout << "Linked List Elements: ";
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Delete first occurrence of a value
    void deleteValue(int val)
    {
        if (head == nullptr)
            return;

        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != val)
            temp = temp->next;

        if (temp->next == nullptr)
        {
            cout << "Value " << val << " not found in this list." << endl;
            return;
        }

        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    // Count nodes
    int countNodes()
    {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Search Element
    bool search(int val)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Reverse List
    void reverseList()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next; // store next
            current->next = prev; // reverse current node's pointer
            prev = current;       // move prev to current
            current = next;       // move to next node
        }
        head = prev; // update head to new first node
    }

    // Sort Linked List
    void List_Sort()
    {
        for (Node *i = head; i != nullptr; i = i->next)
        {
            Node *minNode = i;

            for (Node *j = i->next; j != nullptr; j = j->next)
            {
                if (j->data < minNode->data)
                {
                    minNode = j;
                }
            }

            if (minNode != i)
            {
                int temp = i->data;
                i->data = minNode->data;
                minNode->data = temp;
            }
        }
    }

    // Remove Duplicates
    void removeDuplicates()
    {
        Node *current = head;

        while (current != nullptr && current->next != nullptr)
        {
            if (current->data == current->next->data)
            {
                Node *duplicate = current->next;
                current->next = duplicate->next;
                delete duplicate;
            }
            else
            {
                current = current->next;
            }
        }
    }
};

int main()
{
    SinglyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(60);
    list.insertAtEnd(40);
    list.insertAtEnd(60);
    list.display();

    list.insertAtBeginning(5);
    list.display();

    list.deleteValue(20);
    list.display();

    cout << "Total Number Of Nodes: " << list.countNodes() << endl;

    int val;
    cout << "Enter A Value For Search : ";
    cin >> val;
    if (list.search(val))
        cout << "Value " << val << " found in the list." << endl;
    else
        cout << "Value " << val << " not found in the list." << endl;

    list.reverseList();
    list.display();

    list.List_Sort();
    cout << "Sorted ";
    list.display();

    list.removeDuplicates();
    cout << "After Removing Duplicates ";
    list.display();
    return 0;
}
