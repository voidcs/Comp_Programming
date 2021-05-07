#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

struct dir{
    string type;
    int l, r;
};

int main(){
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    int n;
    cin>>n;
    dir a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i].type>>a[i].l>>a[i].r;
    }
    int l = -1e9, r = 1e9;
    for(int i = n-1; i >= 0; i--){
        if(a[i].type == "none"){
            l = max(l, a[i].l), r = min(r, a[i].r);
        }
        else if(a[i].type == "on"){
            l -= a[i].r;
            r -= a[i].l;
            l = max(l, 0);
        }
        else if(a[i].type == "off"){
            l += a[i].l;
            r += a[i].r;
        }
    }
    cout<<l<<" "<<r<<endl;
    
    l = -1e9, r = 1e9;
    for(int i = 0; i < n; i++){
        if(a[i].type == "none"){
            l = max(l, a[i].l), r = min(r, a[i].r);
        }
        else if(a[i].type == "on"){
            l += a[i].l;
            r += a[i].r;
        }
        else if(a[i].type == "off"){
            l -= a[i].r;
            r -= a[i].l;
            l = max(l, 0);
        }
    }
    cout<<l<<" "<<r<<endl;
    
    return 0;
}