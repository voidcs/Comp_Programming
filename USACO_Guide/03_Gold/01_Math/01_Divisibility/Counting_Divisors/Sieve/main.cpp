#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

int main(){
    ll maxN = 1e6+5;
    vector<ll> gpf(maxN);   //Greatest prime factor that divides index i
    for(int i = 2; i < maxN; i++){
        if(gpf[i] == 0){
            for(int j = i; j < maxN; j += i){
                gpf[j] = i;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans = 1;
        while(n != 1){
            int x = gpf[n];
            int cnt = 1;
            while(gpf[n] == x){
                n /= gpf[n];
                cnt++;
            }
            ans *= cnt;
        }
        cout<<ans<<"\n";
    }
}
