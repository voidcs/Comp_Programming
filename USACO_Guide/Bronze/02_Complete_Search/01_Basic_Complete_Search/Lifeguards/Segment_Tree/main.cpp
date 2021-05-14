#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n;
    cin>>n;
    vector<array<int, 2>> v(n);
    vector<int> vis(1001), solo(1001);
    for(int i = 0; i < n; i++){
        cin>>v[i][0]>>v[i][1];
        vis[v[i][0]]++, vis[v[i][1]]--;
    }
    int sum = 0, have = 0;
    for(int i = 0; i <= 1000; i++){
        sum += vis[i];
        if(sum){
            have++;
            if(sum == 1)
                solo[i] = 1;
        }
    }
    vector<int> tree(4000);
    function<void(int, int, int)> build = [&](int i, int sl, int sr){
        if(sl == sr){
            tree[i] = solo[sl];
            return;
        }
        int mid = (sl + sr) / 2;
        build(2*i+1, sl, mid);
        build(2*i+2, mid+1, sr);
        tree[i] = tree[2*i+1] + tree[2*i+2];
    };
    
    function<int(int, int, int, int, int)> query = [&](int i, int sl, int sr, int ql, int qr){
        if(ql <= sl && sr <= qr)
            return tree[i];
        if(sl > qr || sr < ql)
            return 0;
        int mid = (sl + sr) / 2;
        int l = query(2*i+1, sl, mid, ql, qr);
        int r = query(2*i+2, mid+1, sr, ql ,qr);
        return l + r;
    };
    
    function<void(int, int, int, int, int)> update = [&](int i, int sl, int sr, int index, int x){
        if(sl == sr){
            tree[i] = x;
            return;
        }
        int mid = (sl + sr) / 2;
        if(index <= mid)
            update(2*i+1, sl, mid, index, x);
        else
            update(2*i+2, mid+1, sr, index, x);
        tree[i] = tree[2*i+1] + tree[2*i+2];
    };
    build(0, 0, 1001); 
    int ans = 0;
    for(int i = 0; i < n; i++){
        int l = v[i][0], r = v[i][1];
        int remove = query(0, 0, 1001, l, r-1);
        ans = max(ans, have - remove);
    }
    cout<<ans<<endl;

    return 0;
}
