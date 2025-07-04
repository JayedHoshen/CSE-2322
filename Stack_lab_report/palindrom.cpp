/*
Name : Jayed Hoshen
ID   : 2204076

Task 4: Write a program to check for palindrome using stack
    Input: "madam"
    Output: Palindrome
*/

#include <bits/stdc++.h>
using namespace std;

int MAX;  

class myStack {
private:
    char arr[1000], topIndex;

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

    char peek() {
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

class revStr{
public:
string reverseString(string s) {
    myStack st;

    for (char c : s) st.push(c);

    string ans = "";
    while (!st.isEmpty()) {
        ans += st.peek();
        st.pop();
    }

    return ans;
}};

int main()
{
    cout << "Enter a string  = ";
    string str; cin >> str;

    MAX = str.size();   

    revStr rst;
    string ss =  rst.reverseString(str);

    if(ss == str) cout << "Palindrome\n";
    else cout << "Not Palindrome\n";

    return 0;
}