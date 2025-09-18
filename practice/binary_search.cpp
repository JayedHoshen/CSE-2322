#include <bits/stdc++.h>
#define FIO() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi0(n) for(int i = 0; i < n; i++)
#define ll long long int
using namespace std;

int main()
{
    FIO(); 

    int n; cin >> n;
    int a[n]; fi0(n) cin >> a[i];

    sort(a, a+n);

    int x; cin >> x;
    
    bool ans = false;
    int l = 0, r = n-1;
    while(l <= r) {
        int mid = (l+r) / 2;

        if(a[mid] == x) {
            ans = true;
            break;
        }
        
        if(a[mid] < x) l = mid+1;
        else r = mid-1;
    }

    if(ans) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}