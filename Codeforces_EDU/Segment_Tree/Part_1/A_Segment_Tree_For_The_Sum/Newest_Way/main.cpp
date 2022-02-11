#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;
const ll mod = 1e9+7;

struct segment_tree{
    ll size;
    vector<ll> tree;

    segment_tree(ll n) :size(n){
        tree = vector<ll>(4*size);
    }

    void build(vector<ll> &v, int i, int l, int r){
        if(r - l == 1){
            tree[i] = v[l];
            return;
        }
        int m = (l+r)/2;
        build(v, 2*i+1, l, m);
        build(v, 2*i+2, m, r);
        tree[i] = tree[2*i+1] + tree[2*i+2];
    }

    ll query(int i, int l, int r, int lx, int rx){
        if(lx >= r || rx <= l)
            return 0LL;
        if(l <= lx && rx <= r){
            return tree[i];
        }
        int m = (lx+rx)/2;
        ll leftSum = query(2*i+1, l, r, lx, m);
        ll rightSum = query(2*i+2, l, r, m, rx);
        return leftSum + rightSum;
    }

    void update(int i, int index, int v, int l, int r){
        if(r - l == 1){
            tree[i] = v;
            return;
        }
        int m = (l+r)/2;
        if(index < m){
            update(2*i+1, index, v, l, m);
        }
        else{
            update(2*i+2, index, v, m, r);
        }
        tree[i] = tree[2*i+1] + tree[2*i+2];
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
            cout<<t.query(0, l, r, 0, n)<<endl;
        }
    }
    return 0;
}
