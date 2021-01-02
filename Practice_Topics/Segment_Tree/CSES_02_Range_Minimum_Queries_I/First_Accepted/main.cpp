#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
//PROBLEM LINK
//https://cses.fi/problemset/task/1647

int main(){
    int n, q;
    cin>>n>>q;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];

    int ql, qr;
    ll st [n*4];
    function<void(int, int, int)> build = [&](int index, int ss, int se){
        if(se == ss){
            st[index] = a[se];
            return;
        }
        int mid = (ss + se) / 2;
        build(index*2, ss, mid);
        build(index*2+1, mid+1, se);
        st[index] = min(st[2*index], st[2*index+1]);
    };

    function<ll(int, int, int)> query = [&](int index, int ss, int se){
        if(ql > se || qr < ss){ 
            return INF;
        }
        if(ss >= ql && se <= qr)
            return st[index];
        int mid = (ss + se) / 2;
        ll l = query(index*2, ss, mid);
        ll r = query(index*2+1, mid+1, se);
        return min(l, r);
    };
    build(1, 0, n-1);
    while(q--){
        cin>>ql>>qr;
        ql--, qr--;
        ll ans = query(1, 0, n-1);
        cout<<ans<<endl;
    }
    return 0;
}
