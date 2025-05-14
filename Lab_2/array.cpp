#include <bits/stdc++.h>
#define ll long long int 
using namespace std;


class myArray{
    private:
        ll ara[100000000], size = 0;
    
    public: 
        void create() {
            cin >> ara[size];
            size++;
        }
        void insert(int pos, int val) {
            int tmp = size-1;
            while(tmp >= pos) {
                ara[tmp+1] = ara[tmp];
                tmp--;
            }
            ara[pos] = val;
            size++;
        }

        void traverse() {
            for(int i = 0; i < size; i++) cout << ara[i] << " ";
            cout << endl;
        }
};

int main()
{
    myArray tc;

    while(1) {
        cout << "Can you insert a value (Y/N)?\n";

        char ch; cin >> ch;
        if(ch == 'Y') {
            cout << "Enter your value = ";
            tc.create();
        }
        else break;
    }

    cout << "Can you print your array (Y/N)?\n";
    char cc; cin >> cc;    
    if(cc == 'Y') tc.traverse();

    cout << "Enter a position which you can insert (0 to )?\n";
    int pos; cin >> pos;
    cout << "Enter your value = "; 
    int val; cin >> val;
    tc.insert(pos, val);

    cout << "Can you print your array (Y) ?\n";
    char c; cin >> c;    
    if(c == 'Y') tc.traverse();

    return 0;
}