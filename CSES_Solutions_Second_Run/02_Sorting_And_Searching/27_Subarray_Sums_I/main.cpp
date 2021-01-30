#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n, x;
    cin>>n>>x;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    queue<ll> q;
    ll sum = 0, ans = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        while(!q.empty() && sum > x){
            sum -= q.front();
            q.pop();
        }
        q.push(a[i]);
        if(sum == x)
            ans++;
    }
    cout<<ans<<endl;
    
    return 0;
}