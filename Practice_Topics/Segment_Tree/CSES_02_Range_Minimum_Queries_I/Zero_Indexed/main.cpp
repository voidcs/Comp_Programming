#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
//PROBLEM LINK
//https://cses.fi/problemset/task/1647/

int main(){
    int n, q;
    cin>>n>>q;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    int tree[4*n];
    function<void(int, int, int)> build = [&](int si, int sl, int sr){
        if(sl == sr){
            tree[si] = a[sl];
            return;
        }
        int mid = (sl + sr) / 2;
        build(2*si+1, sl, mid);
        build(2*si+2, mid+1, sr);
        tree[si] = min(tree[2*si+1], tree[2*si+2]);
    };
    
    int ql, qr;
    function<int(int, int, int)> query = [&](int si, int sl, int sr){
        if(ql > sr || qr < sl)
            return INT_MAX;
        else if(sl >= ql && sr <= qr)
            return tree[si];
        int mid = (sl + sr) / 2;
        int l = query(si*2+1, sl, mid);
        int r = query(si*2+2, mid+1, sr);
        return min(l, r);
    };
    
    build(0, 0, n-1);
    while(q--){
        cin>>ql>>qr;
        ql--, qr--;
        cout<<query(0, 0, n-1)<<endl;
    }
    
    return 0;
}