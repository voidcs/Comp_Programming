//https://cses.fi/problemset/task/1647/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n, q;
    cin>>n>>q;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    int pow2 = 0;
    while((1<<(pow2+1)) <= n)
       pow2++; 
    vector<vector<int>> st(pow2+1, vector<int>(n));
    for(int i = 0; i < n; i++){
        st[0][i] = v[i];
    }
    for(int j = 1; j <= pow2; j++){
        for(int i = 0; i < n; i++){
            if(i + (1<<j) <= n){
                st[j][i] = min(st[j-1][i], st[j-1][i + (1<<(j-1))]);
            }
        }
    }
    while(q--){
        int a, b;
        cin>>a>>b;
        a--, b--;
        int p = 0;
        while((1<<(p+1)) <= (b-a+1))
            p++;
        int ans = min(st[p][a], st[p][b-(1<<p)+1]);
        cout<<ans<<endl;
    }
    return 0;
}
