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
    vector<int> tree(n*4);
    int ql, qr, updateIndex, updateValue;
    
    function<void(int, int, int)> build = [&](int si, int sl, int sr){
        if(sl == sr){
            tree[si] = a[sl];
            return;
        }
        int mid = (sl+sr)/2;
        build(2*si+1, sl, mid);
        build(2*si+2, mid+1, sr);
        tree[si] = min(tree[2*si+1], tree[2*si+2]);
    };
    
    function<int(int, int, int)> query = [&](int si, int sl, int sr){
        if(sl > qr || sr < ql)
            return INT_MAX;
        if(sl >= ql && sr <= qr)
            return tree[si];
        int mid = (sl+sr)/2;
        int l = query(2*si+1, sl, mid);
        int r = query(2*si+2, mid+1, sr);
        return min(l, r);
    };
    
    function<void(int, int, int)> update = [&](int si, int sl, int sr){
        if(sl == sr){
            tree[si] = updateValue;
            return;
        }
        int mid = (sl+sr)/2;
        if(updateIndex <= mid)
            update(2*si+1, sl, mid);
        else
            update(2*si+2, mid+1, sr);
        tree[si] = min(tree[2*si+1], tree[2*si+2]);
    };
    build(0, 0, n-1);
    while(q--){
        int x, y, z;
        cin>>x>>y>>z;
        if(x == 1){
            updateIndex = y-1;
            updateValue = z;
            update(0, 0, n-1);
        }
        else{
            ql = y-1, qr = z-1;
            cout<<query(0, 0, n-1)<<endl;
        }
    }
    
    return 0;
}