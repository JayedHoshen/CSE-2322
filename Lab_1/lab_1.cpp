#include <bits/stdc++.h>
using namespace std;

class myArrayClass{
    vector <int> ara;

    public:
        // Input and array with length n
        void inputData() {
            cout << "Enter Array length = ";
            int n; cin >> n;

            cout << "\nEnter Array Value = ";
            for(int i = 0; i < n; i++) {
                int val; cin >> val;
                ara.push_back(val);
            }
        }

        // Output an array
        void outputData() {
            cout << "Array element is = ";
            for(int v : ara) cout << v << " ";
            cout << '\n';
        }

        // Find Largest value
        void findLargest() {
            int mx = INT_MIN;
            for(int i = 0; i < ara.size(); i++) {
                if(ara[i] > mx) mx = ara[i];
            }
            cout << "Largest value = " << mx << '\n';
        }

        // Find Smallest value
        void findSmallest() {
            int mn = INT_MAX;
            for(int i = 0; i < ara.size(); i++) {
                if(ara[i] < mn) mn = ara[i];
            }
            cout << "Smallest value = " << mn << '\n';
        }

        // Find Second Largest value
        void findSecondLargest() {
            int mx = INT_MIN, s_mx = INT_MIN;
            for(int i = 0; i < ara.size(); i++) {
                if(ara[i] > mx) {
                    s_mx = mx;
                    mx = ara[i];
                }
                else if(ara[i] > s_mx) s_mx = ara[i];
            }
            cout << "Second Largest value = " << s_mx << '\n';
        }

        // Find Second Smallest value
        void findSecondSmallest() {
            int mn = INT_MAX, s_mn = INT_MAX;
            for(int i = 0; i < ara.size(); i++) {
                if(ara[i] < mn) {
                    s_mn = mn;
                    mn = ara[i];
                }
                else if(ara[i] < s_mn) s_mn = ara[i];
            }
            cout << "Second Smallest value = " << s_mn << '\n';
        }

        // Remove Duplicate value
        void removeDuplicate() {
            vector <int> v; map <int, int> mp;
            for(int i = 0; i < ara.size(); i++) {
                if(!mp[ara[i]]) v.push_back(ara[i]);
                mp[ara[i]]++;
            }
            ara = v;
        }

        // Merge two array
        vector<int>  mergeTwoArray(vector<int> a, vector<int> b) {
            int n = a.size(), m = b.size();
            vector <int> ans(n+m);

            for(int i = 0; i < n; i++) ans[i] = a[i];
            for(int i = n; i < (n+m); i++) ans[i] = b[i];

            return ans;
        }

        // Find Sum and Product
        void findSumAndProduct() {
            int sum = 0, product = 1;
            for(int i = 0; i < ara.size(); i++) {
                sum += ara[i];
                product *= ara[i];
            }
            cout << "Summation = " << sum << '\n' << "Product = " << product << '\n';
        }

        // Print Given Position
        void printGivenPosition(int pos) {
            if(pos < ara.size()) {
                cout << "ara[" << pos << "] = " << ara[pos] << '\n';
            }
            else cout << "Try again, valid position is (0 to " << ara.size() - 1 << " )\n";
        }
};

int main()
{
    myArrayClass tc;

    tc.inputData();
    cout << "Before Duplicate Remove ";
    tc.outputData();

    tc.removeDuplicate();
    cout << "After Duplicate Remove "; 
    tc.outputData();

    tc.findLargest();
    tc.findSmallest();
    tc.findSecondLargest();
    tc.findSecondSmallest();
    tc.findSumAndProduct();

    cout << "Enter position which value you watch = ";
    int m; cin >> m;
    tc.printGivenPosition(m);

    // here two array input than merge this two array
    cout << "Enter two array that you merge----\n";
    cout << "1st array size = ";
    vector <int> v1, v2, ans;
    int n; cin >> n;
    cout << "Enter array value = ";
    while(n--) {
        int val; cin >> val;
        v1.push_back(val);
    }

    cout << "2nd array size = ";
    int m; cin >> m;
    cout << "Enter array value = ";
    while(m--) {
        int val; cin >> val;
        v1.push_back(val);
    }

    ans = tc.mergeTwoArray(v1, v2);
    for(int val : ans) cout << val << " ";
    cout << '\n';

    return 0;
}