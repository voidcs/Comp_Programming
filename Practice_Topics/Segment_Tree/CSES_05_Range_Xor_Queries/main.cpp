#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
//PROBLEM LINK
//https://cses.fi/problemset/task/1650

int main(){
    int n, q;
    cin>>n>>q;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    vector<ll> tree(n*4);
    int ql, qr;
    function<void(int, int, int)> build = [&](int si, int sl, int sr){
        if(sl == sr){
            tree[si] = a[sl];
            return;
        }
        int mid = (sl+sr)/2;
        build(2*si+1, sl, mid);
        build(2*si+2, mid+1, sr);
        tree[si] = (tree[2*si+1] ^ tree[2*si+2]);
    };
    function<ll(int, int, int)> query = [&](int si, int sl, int sr){
        if(sl > qr || sr < ql)
            return (ll)0;
        else if(sl >= ql && sr <= qr)
            return tree[si];
        int mid = (sl+sr)/2;
        ll l = query(2*si+1, sl, mid);
        ll r = query(2*si+2, mid+1, sr);
        return (l ^ r);
    };
    build(0, 0, n-1);
    while(q--){
        cin>>ql>>qr;
        ql--, qr--;
        cout<<query(0, 0, n-1)<<endl;
    }
    return 0;
}