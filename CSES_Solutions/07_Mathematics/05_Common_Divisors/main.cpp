#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e6;
int cnt[maxN+1];

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    
    for(int i = 0; i < n; i++)
        cnt[a[i]]++;
    
    //i represents a potential GCD we are trying
    for(int i = maxN; i; i--){
        ll c = 0;
        for(int j = i; j <= maxN; j += i)
            c += cnt[j];
        if(c > 1){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}