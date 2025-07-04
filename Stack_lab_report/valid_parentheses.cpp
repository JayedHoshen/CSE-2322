/*
Name : Jayed Hoshen
ID   : 2204076

Task 2: Write a program to check for balanced parentheses
    Input: A string of parentheses ({[()]})
    Output: Whether it is balanced or not using a stack.
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

class parentheses {
public:
bool isValid(string s) {
    myStack st;
    for(char c : s) {
        if(c == '(' || c == '{' || c == '[')  st.push(c);
        else {
            if(st.isEmpty())  return false;
            else {
                if(c == ')' && st.peek() == '(') st.pop();
                else if(c == '}' && st.peek() == '{') st.pop();
                else if(c == ']' && st.peek() == '[') st.pop();
                else return false;
                
            }
        }
    }
    return st.isEmpty();
}};

int main()
{
    cout << "Enter a string of parentheses = ";
    string str; cin >> str;

    MAX = str.size();    
    parentheses p;

    if(p.isValid(str)) cout << "Valid parentheses\n";
    else cout << "Not valid parentheses\n";

    return 0;
}