#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> in(n+1), out(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin>>a>>b;
        in[b]++;
        out[a]++;
    }
    int ans = -1, sinks = 0;
    for(int i = 1; i <= n; i++){
        if(out[i] == 0){
            sinks++;
            ans = i;
        }
    }
    cout<<((sinks == 1) ? ans : -1)<<endl;
    return 0;
}
