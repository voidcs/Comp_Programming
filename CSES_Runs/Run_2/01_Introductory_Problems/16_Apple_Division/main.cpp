#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll sum = 0;
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum += a[i];
    }
    ll ans = INF;
    for(int i = 0; i < 1<<n; i++){
        ll groupSum = 0;
        for(int j = 0; j < n; j++){
            if(i & 1<<j){
                groupSum += a[j];
            }
        }
        ll otherGroup = sum - groupSum;
        ans = min(ans, abs(groupSum - otherGroup));
    }
    cout<<ans<<endl;
    
    return 0;
}