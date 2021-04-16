#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/230/A

int main(){
    int s, n;
    cin>>s>>n;
    array<int, 2> a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i][0]>>a[i][1];
    }
    sort(a, a + n);
    bool win = 1;
    for(int i = 0; i < n; i++){
        if(s <= a[i][0])
            win = 0;
        else
            s += a[i][1];
    }
    if(win)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}

 