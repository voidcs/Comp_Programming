#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    int n, d;
    cin>>n>>d;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
        
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j){
                if(abs(a[i]-a[j]) <= d){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}