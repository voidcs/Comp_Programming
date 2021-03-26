#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<ll> tree(4*n);
    int ql, qr, x, v;
    
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
    
    function<void(int, int, int, int, int)> update = [&](int u, int x, int i, int l, int r){
        if(l == r){
            tree[i] = x;
            return;
        }
        int mid = (l+r)/2;
        if(u <= mid)
            update(u, x, 2*i+1, l, mid);
        else
            update(u, x, 2*i+2, mid+1, r);
        tree[i] = tree[2*i+1] + tree[2*i+2];
    };
    for(int i = 0; i < n; i++){
        cin>>x;
        update(i, x, 0, 0, n-1);
    }
    while(m--){
        int q;
        cin>>q;
        if(q == 1){
            cin>>x>>v;
            update(x, v, 0, 0, n-1);
        }
        if(q == 2){
            cin>>ql>>qr;
            qr--;
            cout<<query(0, 0, n-1)<<endl;
        }
    }
    
    return 0;
}