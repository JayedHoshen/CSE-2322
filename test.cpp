#include <bits/stdc++.h>
#define FIO() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi0(n) for(int i = 0; i < n; i++)
#define ll long long int
using namespace std;

int main()
{
    FIO(); 

    int n;
    cin >> n;

    int ara[n];
    for(int i = 0; i < n; i++) cin >> ara[i];

    int x;
    cin >> x;

    int l = 0; 
    int r = n - 1;
    bool flag = false;

    while(l <= r) {
        int mid_index = (l+r) / 2;

        if(ara[mid_index] == x) {
            flag = true;
            break;
        }

        if(x > ara[mid_index]) l = mid_index + 1;
        else r = mid_index - 1;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}