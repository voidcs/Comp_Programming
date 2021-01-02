#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
//PROBLEM LINK
//https://cses.fi/problemset/task/1646

int main(){
    int n, q;
    cin>>n>>q;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    vector<ll> tree(n*4);
    
    function<void(int, int, int)> build = [&](int si, int sl, int sr){
        if(sl == sr){
            tree[si] = a[sl];
            return;
        }
        int mid = (sl+sr)/2;
        build(si*2+1, sl, mid);
        build(si*2+2, mid+1, sr);
        tree[si] = tree[si*2+1] + tree[si*2+2];
    };
    int ql, qr;
    function<ll(int, int, int)> query = [&](int si, int sl, int sr){
        if(sl > qr || sr < ql)
            return (ll)0;
        if(sl >= ql && sr <= qr)
            return tree[si];
        int mid = (sl+sr)/2;
        ll l = query(si*2+1, sl, mid);
        ll r = query(si*2+2, mid+1, sr);
        return l + r;
    };
    build(0, 0, n-1);
    while(q--){
        cin>>ql>>qr;
        ql--, qr--;
        cout<<query(0, 0, n-1)<<endl;
    }
    
    return 0;
}