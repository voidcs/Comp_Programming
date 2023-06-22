#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin>>n>>m>>q;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    vector<int> cnt(1<<n);
    while(m--){
        string s;
        cin>>s;
        cnt[stoi(s, nullptr, 2)]++;
    }
    vector<vector<int>> ans(1<<n);
    //For all possible query strings, calculate how many multiset elements have sum <= 100
    for(int i = 0; i < (1<<n); i++){
        ans[i] = vector<int>(101);
        for(int x = 0; x < (1<<n); x++){
            int f = cnt[x];
            ll sum = 0;
            int u = x;
            ll active = ~(i ^ u);
            for(int j = 0; j < n; j++){
                if(active & (1 << j))
                    sum += v[n - j - 1];
            }
            if(sum <= 100)
                ans[i][sum] += f;
        }
        ll sum = 0;
        for(int j = 0; j <= 100; j++){
            sum += ans[i][j];
            ans[i][j] = sum;
        }
    }
    while(q--){
        string s;
        int k;
        cin>>s>>k;
        int x = stoi(s, nullptr, 2);
        cout<<ans[x][k]<<"\n";
    }
}