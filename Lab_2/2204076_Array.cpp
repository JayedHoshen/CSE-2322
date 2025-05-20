/*
    CSE 2522        : Data Structure Sessional
    Lab report-02.2 : Insert/Delete at first/last/at any position (An array) 
    Student_id      : 2204076
    Student_name    : Jayed hoshen
    Section         : B

---------->> Table of Content <<----------
01) insert at last
02) insert at first
03) insert at position
04) delete at first
05) delete at last
06) delete at position
07) Print array
08) Main Function
*/

#include<bits/stdc++.h>
using namespace std;

class myArray_2204076{
    int ara[30000], n = 0;
public:
    // 01) insert at last
    void insert_Last_076(int val){
        ara[n] = val;
        n++;
    }

    // 02) insert at first
    void insert_first_076(int val){
        n++;
        for(int i = n; i > 0; i--) ara[i] = ara[i-1];
        ara[0] = val;
    }

    // 03) insert at position
    void insert_position_076(int pos, int val){
        n++;
        for(int i = n; i > pos; i--) ara[i] = ara[i-1];
        ara[pos] = val;
    }

    // 04) delete at first
    void delete_first_076(){
        n--;
        for(int i = 0; i < n; i++) ara[i] = ara[i+1];
    }

    // 05) delete at last
    void delete_last_076(){
        n--;
    }

    // 06) delete at position
    void delete_position_076(int pos){
        n--;
        for(int i = pos; i < n; i++) ara[i] = ara[i+1];
    }

    // 07) Print array
    void display_076(){
        cout << "My array = ";
        for(int i = 0; i < n; i++) cout << ara[i] << " ";
        cout << endl;
    }
};

// *********** Main Function Start **********
int main()
{
    myArray_2204076 obj;

    int tc;
    cout << "\nHow many element you want to insert = ";
    cin >> tc;

    while(tc--){
        int data;
        cout << "Enter data : "; cin >> data;
        obj.insert_Last_076(data);
    }
    
    obj.display_076();

    // insert at first
    cout << "\nEnter a value (insert first) = ";
    int x; cin >> x;
    obj.insert_first_076(x);
    cout << "\nAfter inserted first -----\n";
    obj.display_076();

    // insert at last
    cout << "\nEnter a value (insert last) = ";
    int v; cin >> v;
    obj.insert_Last_076(v);
    cout << "\nAfter inserted last -----\n";
    obj.display_076();

    // insert at position
    cout << "\nEnter a position and a value which you insert (0 to start) = ";
    int y, p; cin >> p >> y;
    obj.insert_position_076(p, y);
    cout << "\nAfter inserted " << p << "th position -----\n";
    obj.display_076();

    // delete first value
    obj.delete_first_076();
    cout << "\nAfter delete first value -----------\n";
    obj.display_076();

    // delete any position value
    cout << "\nEnter a position that delete a value = ";
    int po; cin >> po;
    obj.delete_position_076(po);
    cout << "\nAfter delete " << po << "th position------\n";
    obj.display_076();

    // delete last value
    obj.delete_last_076(); 
    cout << "\nAfter delete last value -----------\n";
    obj.display_076();

    return 0;
}