#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
int main(){
    //freopen("input.txt", "r", stdin);
    ll n, k;
    cin>>n>>k;
    ll a[k];
    for(int i = 0; i < k; i++){
        cin>>a[i];
    }
    long long ans = 0;
    for(int i = 0; i < k; i++){
        ans += n/a[i];
    }

    ll sum = 0;
    for(int i = 0; i < (1<<k); i++){
        ll cnt = 0;
        ll temp = n;
        for(int j = 0; j < k; j++){
            if(i & 1<<j){
                cnt++;
                temp /= a[j];
            }
        }
        if(cnt%2)
            sum -= temp;
        else
            sum += temp;
        }

    cout<<n - sum<<endl;
    return 0; 
} 
