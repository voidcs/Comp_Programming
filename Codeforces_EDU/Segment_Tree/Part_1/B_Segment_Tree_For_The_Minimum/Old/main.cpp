#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<ll> tree(4*n);
    vector<ll> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    
    function<void(int, int, int)> build = [&](int i, int l, int r){
        if(l == r){
            tree[i] = v[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*i+1, l, mid);
        build(2*i+2, mid+1, r);
        tree[i] = min(tree[2*i+1], tree[2*i+2]);
    };
    
    function<void(int, ll, int, int, int)> update = [&](int updateIndex, ll x, int i, int l, int r){
        if(l == r){
            tree[i] = x;
            return;
        }
        int mid = (l+r)/2;
        if(updateIndex <= mid)
            update(updateIndex, x, 2*i+1, l, mid);
        else
            update(updateIndex, x, 2*i+2, mid+1, r);
        tree[i] = min(tree[2*i+1], tree[2*i+2]);
    };
    
    function<ll(int, int, int, int, int)> query = [&](int ql, int qr, int i, int l, int r){
        if(l > qr || r < ql)
            return INF;
        if(l >= ql && r <= qr)
            return tree[i];
        int mid = (l+r)/2;
        ll left = query(ql, qr, 2*i+1, l, mid);
        ll right = query(ql, qr, 2*i+2, mid+1, r);
        return min(left, right);
    };
    
    build(0, 0, n-1);
    
    while(m--){
        int x, y, z;
        cin>>x>>y>>z;
        if(x == 1)
            update(y, z, 0, 0, n-1);
        else if(x == 2)
            cout<<query(y, z-1, 0, 0, n-1)<<endl;
    }
    
    return 0;
}