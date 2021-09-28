#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    ll n, x;
    cin>>n>>x;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    
    unordered_map<ll, array<ll, 2>> m;
    m.reserve(1<<19);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            m[a[i]+a[j]] = {i, j};
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ll need = x - a[i] - a[j];
            if(m.count(need) && i != m[need][0] && i != m[need][1] && j != m[need][0] && j != m[need][1]){
                cout<<i+1<<" "<<j+1<<" "<<m[need][0]+1<<" "<<m[need][1]+1<<endl;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
    
    return 0;
}