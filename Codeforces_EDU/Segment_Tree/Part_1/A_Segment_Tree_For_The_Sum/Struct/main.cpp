#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

struct segTree{
    int n;
    vector<ll> tree;
    
    void init(int size){
        n = size;
        tree = vector<ll>(n*4);
    }
    
    void update(int u, ll x, int i, int l, int r){
        if(l == r){
            tree[i] = x;
            return;
        }
        int mid = (l + r) / 2;
        if(u <= mid)
            update(u, x, 2*i+1, l, mid);
        else
            update(u, x, 2*i+2, mid+1, r);
        tree[i] = tree[2*i+1] + tree[2*i+2];
    }
    
    ll query(int ql, int qr, int i, int l, int r){
        if(l > qr || r < ql)
            return 0LL;
        if(l >= ql && r <= qr)
            return tree[i];
        int mid = (l + r) / 2;
        ll sumL = query(ql, qr, 2*i+1, l, mid);
        ll sumR = query(ql, qr, 2*i+2, mid+1, r);
        return sumL + sumR;
    }
    
};

int main(){
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    segTree st;
    st.init(n);
    for(int i = 0; i < n; i++){
        int x; 
        cin>>x;
        st.update(i, x, 0, 0, n-1);
    }

    while(m--){
        int x, y, z;
        cin>>x>>y>>z;
        if(x == 1){
            st.update(y, z, 0, 0, n-1);
        }
        if(x == 2){
            cout<<st.query(y, z-1, 0, 0, n-1)<<endl;
        }
    }
    
    return 0;
}