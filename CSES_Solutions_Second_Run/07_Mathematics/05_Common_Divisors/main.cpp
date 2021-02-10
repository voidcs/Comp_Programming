#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll maxN = 1e6+5;
    ll n;
    cin>>n;
    ll a[n];
    vector<int> cnt(maxN, 0);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i = maxN-1; i >= 1; i--){
        ll have = 0;
        for(int j = i; j < maxN; j += i){
            have += cnt[j];
        }
        if(have > 1){
            cout<<i<<endl;
            return 0;
        }
    }
    
    return 0;
}