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

    ll sum = 0;
    for(int i = 0; i < (1<<k); i++){
        ll cnt = 0;
        __int128 prod = 1;
        bool flag = 0;
        for(int j = 0; j < k; j++){
            if(i & 1<<j){
                cnt++;
                prod *= a[j];
                if(prod > n){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
            continue;
        ll curr = n / prod;
        if(cnt%2)
            sum -= curr;
        else
            sum += curr;
        }

    cout<<n - sum<<endl;
    return 0; 
} 
