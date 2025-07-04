/*
Name : Jayed Hoshen
ID   : 2204076

Task 1: Write a program to implement a stack using an array. Implement the following operations:
    push()
    pop()
    peek()
    isEmpty()
    isFull()
*/

#include <bits/stdc++.h>
using namespace std;

int MAX;  

class myStack {
private:
    int arr[1000], topIndex;

public:
    myStack() { 
        topIndex = -1; 
    }

    void push(int val) {
        if (topIndex < MAX - 1)  arr[++topIndex] = val;
        else cout << "Stack Overflow\n";
    }

    void pop() {
        if (topIndex >= 0)topIndex--;
        else  cout << "Stack Underflow\n";
    }

    int peek() {
        if (topIndex >= 0) return arr[topIndex];
        else {
            cout << "Stack is Empty\n";
            return -1;
        }
    }

    int size() {
        return topIndex + 1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return (MAX-1 == topIndex);
    }
};

int main()
{
    myStack st;

    cout << "Enter stack size = "; cin >> MAX;

    cout << "Enter your value = ";
    for(int i = 0; i < MAX; i++) {
        int val; cin >> val;
        if (!st.isFull()) st.push(val);
    }

    cout << "Stack value is = ";
    while(!st.isEmpty()) {
        cout << st.peek() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}