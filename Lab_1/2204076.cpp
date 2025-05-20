/*
    CSE 2522        : Data Structure Sessional
    Lab report-01   : Introduction to Arrays 
    Student_id      : 2204076
    Student_name    : Jayed hoshen
    Section         : B

---------->> Table of Content <<----------
01) Create and array.
02) Find Largest Element
03) Find Smallest Element
04) Find Second Largest Element
05) Find Second Smallest Element
06) Remove Duplicates from an Array
07) Merge Two Arrays
08) Find Sum of Elements
09) Find Product of Elements
10) Display array
11) Print Element at Given Position
12) Main Function
*/

#include<bits/stdc++.h>
using namespace std;

class myArray{
    int arr[30000];
    int n = 0;
public:
    // 01) Create an array
    void createArray_076() {
        cout << "Enter an array (-1 to break) = ";
        int x, i = 0;
        while(true) {
            cin >> x;
            if (x == -1) break;
            arr[i] = x;
            i++; n++;
        }
    }

    // 02) Find Largest Element
    void find_largest_076() {
        int mx = INT_MIN;
        for(int i = 0; i < n; i++) if(arr[i] > mx) mx = arr[i];
        cout << "Largest element is = " << mx << endl;
    }

    // 03) Find Smallest Element
    void find_smallest_076() {
        int mn = INT_MAX;
        for(int i = 0; i < n; i++) if(arr[i] < mn) mn = arr[i];
        cout << "Smallest element is = " << mn << endl;
    }

    // 04) Find Second Largest Element
    void find_second_largest_076() {
        int first_largest = INT_MIN;
        int second_largest = INT_MIN;

        for(int i = 0; i < n; i++) {
            if(arr[i] > first_largest) {
                second_largest = first_largest;
                first_largest = arr[i];
            }
            else if(arr[i] > second_largest) second_largest = arr[i];
        }
        cout << "Second largest element is = " << second_largest << endl;
    }

    // 05) Find Second Smallest Element
    void find_second_smallest_076(){
        int first_smallest = INT_MAX;
        int second_smallest = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(arr[i] < first_smallest) {
                second_smallest = first_smallest;
                first_smallest = arr[i];
            }
            else if(arr[i] < second_smallest) second_smallest = arr[i];
        }
        cout << "Second Smallest element is = " << second_smallest << endl;
    }

    // 06) Remove Duplicates from an Array
    void remove_duplicate_076() {
        map <int, int> mp;
        for(int i = 0; i < n; i++) mp[arr[i]]++;

        n = 0;
        for(auto element:mp) {
            arr[n] = element.first;
            n++;
        }
    }

    // 07) Merge Two Arrays
    void marge_array_076() {
        cout << "\nEnter two array that you can merge ------\n";

        int n; 
        cout << "Enter first array length = "; cin >> n;

        int ara1[n]; cout << "Enter first array value = ";
        for(int i = 0; i < n; i++) cin >> ara1[i];

        int m; 
        cout << "Enter second array length = "; cin >> m;

        int ara2[m]; cout << "Enter second array value ";
        for(int i = 0; i < m; i++) cin >> ara2[i];

        int mgAra[n+m];
        for (int i = 0; i < n; i++) mgAra[i] = ara1[i];
        for (int i = 0; i < m; i++)  mgAra[n+i] = ara2[i];

        cout << "After Merge (two array) = ";
        for (int i = 0; i < (n+m); i++) cout << mgAra[i] << " ";
    }

    // 08) Find Sum of Elements
    void find_sum_076() {
        int sum = 0;
        for(int i = 0; i < n; i++) sum += arr[i];
        cout << "Summation is = " << sum << endl;
    }

    // 09) Find Product of Elements
    void find_product_076() {
        long long int product = 1;
        for(int i = 0; i < n; i++) product *= arr[i];
        cout << "Product is = " << product << endl;
    }

    // 10) Display array
    void display_076() {
        cout << "Array values = ";
        for(int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }

    // 11) Print Element at Given Position
    void printPosition_076(int pos) {
        if(pos >= n) cout << "Enter a valid position (0 to " << n-1 << ")\n";
        else cout << "Array value is = " << arr[pos] << endl;
    }
};

// *********** Main Function Start **********
int main()
{
    myArray obj;

    obj.createArray_076();

    cout << "\nBefore Duplicate Remove\n";
    obj.display_076();
    obj.remove_duplicate_076();
    cout << "After Duplicate remove -----\n";
    obj.display_076();
    cout << endl;

    obj.find_sum_076();
    obj.find_product_076();
    obj.find_smallest_076();
    obj.find_largest_076();
    obj.find_second_smallest_076();
    obj.find_second_largest_076();
    cout << endl;

    obj.display_076();
    cout << "Enter a position = ";
    int x; cin >> x;
    obj.printPosition_076(x);

    obj.marge_array_076();

    return 0;
}