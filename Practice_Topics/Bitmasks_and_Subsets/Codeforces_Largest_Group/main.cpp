#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/gym/101915/problem/D

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> boys(n, 0);
        vector<int> girls(n, 0);
        while(m--){
            int a, b;
            cin>>a>>b;
            a--, b--;
            boys[a] |= (1<<b);
            girls[b] |= (1<<a);
        }
        
        int ans = n;
        for(int i = 0; i < 1<<n; i++){
            int mask = (1<<n) - 1;
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(i & (1<<j)){
                    mask &= boys[j];
                    cnt++;
                }
            }
            ans = max(ans, cnt + __builtin_popcount(mask));
        }
        cout<<ans<<endl;
    }
    
    return 0;
}