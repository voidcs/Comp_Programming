#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;
const ll mod = 1e9+7;

struct segment_tree{
    array<ll, 2> neutral = {INF, 0};
    ll size;
    vector<array<ll, 2>> tree;

    segment_tree(ll n) :size(n){
        tree = vector<array<ll, 2>>(4*size);
    }

    void build(vector<ll> &v, int i, int l, int r){
        if(r - l == 1){
            tree[i] = {v[l], 1};
            return;
        }
        int m = (l+r)/2;
        build(v, 2*i+1, l, m);
        build(v, 2*i+2, m, r);
        array<ll, 2> a = tree[2*i+1];
        array<ll, 2> b = tree[2*i+2];
        if(a[0] < b[0])
            tree[i] = a;
        else if(b[0] < a[0])
            tree[i] = b;
        else
            tree[i] = {a[0], a[1] + b[1]};
    }

    array<ll, 2> query(int i, int l, int r, int lx, int rx){
        if(lx >= r || rx <= l)
            return neutral;
        if(l <= lx && rx <= r){
            return tree[i];
        }
        int m = (lx+rx)/2;
        array<ll, 2> a = query(2*i+1, l, r, lx, m);
        array<ll, 2> b = query(2*i+2, l, r, m, rx);
        if(a[0] < b[0])
            return a;
        else if(b[0] < a[0])
            return b;
        else{
            return {a[0], a[1] + b[1]};
        }
    }

    void update(int i, int index, int v, int l, int r){
        if(r - l == 1){
            tree[i] = {v, 1};
            return;
        }
        int m = (l+r)/2;
        if(index < m){
            update(2*i+1, index, v, l, m);
        }
        else{
            update(2*i+2, index, v, m, r);
        }
        array<ll, 2> a = tree[2*i+1];
        array<ll, 2> b = tree[2*i+2];
        if(a[0] < b[0])
            tree[i] = a;
        else if(b[0] < a[0])
            tree[i] = b;
        else
            tree[i] = {a[0], a[1] + b[1]};
    }
};

int main(){
    int n, m;
    cin>>n>>m;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    segment_tree t(n);
    t.build(v, 0, 0, n);
    while(m--){
        ll op;
        cin>>op;
        if(op == 1){
            ll i, v;
            cin>>i>>v;
            t.update(0, i, v, 0, n);
        }
        else if(op == 2){
            int l, r;
            cin>>l>>r;
            array<ll, 2> ans = t.query(0, l, r, 0, n);
            cout<<ans[0]<<" "<<ans[1]<<"\n";
        }
    }
    return 0;
}
