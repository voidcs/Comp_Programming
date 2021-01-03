#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    int n, q;
    cin>>n>>q;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    vector<ll> tree(n*4, 0), lazy(n*4, 0);
    int ql, qr, updateValue;
    function<void(int, int, int)> build = [&](int si, int sl, int sr){
        if(sl == sr){
            tree[si] = a[sl];
            return;
        }
        int mid = (sl+sr)/2;
        build(2*si+1, sl, mid);
        build(2*si+2, mid+1, sr);
        tree[si] = tree[2*si+1] + tree[2*si+2];
    };
    function<ll(int, int, int)> query = [&](int si, int sl, int sr){
        if(lazy[si]){
            ll dx = lazy[si];
            lazy[si] = 0;
            tree[si] += dx*(sr-sl+1);
            if(sl != sr){
                lazy[2*si+1] += dx;
                lazy[2*si+2] += dx;
            }
        }
        if(sl > qr || sr < ql)
            return (ll)0;
        if(sl >= ql && sr <= qr){
            return tree[si];
        }
        int mid = (sl+sr)/2;
        ll l = query(2*si+1, sl, mid);
        ll r = query(2*si+2, mid+1, sr);
        return (l+r);
    };
    function<void(int, int, int)> update = [&](int i, int sl, int sr){
        if(lazy[i]){
            ll dx = lazy[i];
            lazy[i] = 0;
            tree[i] += dx*(sr-sl+1);
            if(sl != sr){
                lazy[2*i+1] += dx;
                lazy[2*i+2] += dx;
            }
        }
        if(sl > qr || sr < ql)
            return;
        if(sl >= ql && sr <= qr){
            ll dx = updateValue * (sr-sl+1);
            tree[i] += dx;
            if(sl != sr){
                lazy[2*i+1] += updateValue;
                lazy[2*i+2] += updateValue;
            }
            return;
        }
        int mid = (sl+sr)/2;
        update(2*i+1, sl, mid);
        update(2*i+2, mid+1, sr);
        tree[i] += (tree[2*i+1] + tree[2*i+2]); 
    };
    build(0, 0, n-1);
    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            cin>>ql>>qr>>updateValue;
            ql--, qr--;
            update(0, 0, n-1);
        }
        else{
            cin>>ql;
            ql--;
            qr = ql;
            cout<<query(0, 0, n-1)<<endl;
        }
    }
    return 0;
}