#include <bits/stdc++.h>
#define FIO() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi0(n) for(int i = 0; i < n; i++)
#define ll long long int
using namespace std;

int main()
{
    FIO(); 
    
    int n; cin >> n;
    int ara[n];
    for(int i = 0; i < n; i++) cin >> ara[i];

    int pre[n];
    pre[0] = ara[0];
    for(int i = 1; i < n; i++) pre[i] = ara[i] + pre[i-1];

    cout << "prefix sum: ";
    for(int v : pre) cout << v << " ";
    cout << endl;

    int l, r, sum; cin >> l >> r;
    if(l == 0) sum = pre[r];
    else sum = pre[r] - pre[l-1];
    cout << sum << endl;

    return 0;
}