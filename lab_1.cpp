#include <bits/stdc++.h>
using namespace std;

class myArrayClass{
    vector <int> ara;

    public:
        void inputData() {
            cout << "Enter Array length = ";
            int n; cin >> n;

            cout << "\nEnter Array Value = ";
            for(int i = 0; i < n; i++) {
                int val; cin >> val;
                ara.push_back(val);
            }
        }

        void outputData() {
            cout << "Array element is = ";
            for(int v : ara) cout << v << " ";
            cout << '\n';
        }

        void findLargest() {
            int mx = INT_MIN;
            for(int i = 0; i < ara.size(); i++) {
                if(ara[i] > mx) mx = ara[i];
            }
            cout << "Largest value = " << mx << '\n';
        }

        void findSmallest() {
            int mn = INT_MAX;
            for(int i = 0; i < ara.size(); i++) {
                if(ara[i] < mn) mn = ara[i];
            }
            cout << "Smallest value = " << mn << '\n';
        }

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

        void removeDuplicate() {
            vector <int> v; map <int, int> mp;
            for(int i = 0; i < ara.size(); i++) {
                if(!mp[ara[i]]) v.push_back(ara[i]);
                mp[ara[i]]++;
            }
            ara = v;
        }

        vector<int>  mergeTwoArray(vector<int> a, vector<int> b) {
            
        }

        void findSumAndProduct() {
            int sum = 0, product = 1;
            for(int i = 0; i < ara.size(); i++) {
                sum += ara[i];
                product *= ara[i];
            }
            cout << "Summation = " << sum << '\n' << "Product = " << product << '\n';
        }

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

    return 0;
}