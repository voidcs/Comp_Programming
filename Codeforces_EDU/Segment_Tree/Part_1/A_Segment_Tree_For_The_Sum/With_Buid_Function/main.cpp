#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    vector<ll> tree(4*n);
    int ql, qr, x, v;
    function<void(int, int, int)> build = [&](int i, int l, int r){
        if(l == r){
            tree[i] = a[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*i+1, l, mid);
        build(2*i+2, mid+1, r);
        tree[i] = tree[2*i+1] + tree[2*i+2];
    };
    
    function<ll(int, int, int)> query = [&](int i, int l, int r){
        if(l > qr || r < ql){
            return 0LL;
        }
        if(l >= ql && r <= qr){
            return tree[i];
        }
        int mid = (l+r)/2;
        ll sumL = query(2*i+1, l, mid);
        ll sumR = query(2*i+2, mid+1, r);
        return sumL + sumR;
    };
    
    function<void(int, int, int)> update = [&](int i, int l, int r){
        if(l == r){
            tree[i] = v;
            return;
        }
        int mid = (l+r)/2;
        if(x <= mid)
            update(2*i+1, l, mid);
        else
            update(2*i+2, mid+1, r);
        tree[i] = tree[2*i+1] + tree[2*i+2];
    };
    
    build(0, 0, n-1);
    while(m--){
        int q;
        cin>>q;
        if(q == 1){
            cin>>x>>v;
            update(0, 0, n-1);
        }
        if(q == 2){
            cin>>ql>>qr;
            qr--;
            cout<<query(0, 0, n-1)<<endl;
        }
    }
    
    return 0;
}