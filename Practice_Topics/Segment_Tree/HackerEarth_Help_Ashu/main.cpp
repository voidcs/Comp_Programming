#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

//PROBLEM LINK
//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/description/

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    vector<array<int, 2>> tree(n*4, {0, 0});
    int ql, qr, updateIndex, updateValue;
    
    function<void(int, int, int)> build = [&](int si, int sl, int sr){
        if(sl == sr){
            if(a[sl]%2)
                tree[si][1]++;
            else
                tree[si][0]++;
            return;
        }
        int mid = (sl+sr)/2;
        build(2*si+1, sl, mid);
        build(2*si+2, mid+1, sr);
        tree[si][0] = (tree[2*si+1][0] + tree[2*si+2][0]);
        tree[si][1] = (tree[2*si+1][1] + tree[2*si+2][1]);
    };
    function<int(int, int, int, int)> query = [&](int si, int sl, int sr, int type){
        if(sl > qr || sr < ql){
            return 0;
        }
        if(sl >= ql && sr <= qr){
            if(type == 1)
                return tree[si][0];
            else
                return tree[si][1];
        }
        int mid = (sl+sr)/2;
        int l = query(2*si+1, sl, mid, type);
        int r = query(2*si+2, mid+1, sr, type);
        return (l+r);
    };
    function<void(int, int, int)> update = [&](int si, int sl, int sr){
        if(sl == sr){
            if(a[sl]%2)
                tree[si][1]--;
            else
                tree[si][0]--;
            if(updateValue%2)
                tree[si][1]++;
            else
                tree[si][0]++;
            a[sl] = updateValue;
            return;
        }
        int mid = (sl+sr)/2;
        if(updateIndex <= mid)
            update(2*si+1, sl, mid);
        else
            update(2*si+2, mid+1, sr);
        tree[si][0] = tree[2*si+1][0] + tree[2*si+2][0];
        tree[si][1] = tree[2*si+1][1] + tree[2*si+2][1];
    };
    
    build(0, 0, n-1);
    int q;
    cin>>q;
    while(q--){
        int x, y;
        int t;
        cin>>t>>x>>y;
        if(!t){
            updateIndex = x-1;
            updateValue = y;
            update(0, 0, n-1);
        }
        else{
            ql = x-1;
            qr = y-1;
            cout<<query(0, 0, n-1, t)<<endl;
        }
    }
    return 0;
}