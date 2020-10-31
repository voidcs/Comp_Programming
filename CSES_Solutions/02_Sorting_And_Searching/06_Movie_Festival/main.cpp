#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n;
    cin>>n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i].second>>a[i].first;
    
    sort(a.begin(), a.end());
    ll ans = 1;
    ll last = a[0].first;
    for(int i = 1; i < n; i++){
        if(a[i].second >= last){
            ans++;
            last = a[i].first;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}