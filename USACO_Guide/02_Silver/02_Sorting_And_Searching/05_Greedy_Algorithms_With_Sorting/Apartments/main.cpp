#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n, m, k;
    cin>>n>>m>>k;
    vector<ll> person(n), apartment(m);
    for(ll &x: person)
        cin>>x;
    for(ll &x: apartment)
        cin>>x;
    sort(person.begin(), person.end());
    sort(apartment.begin(), apartment.end());
    ll j = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(j == m)
            continue;
        while(j < m && person[i] - apartment[j] > k)
            j++;
        if(j < m && abs(person[i] - apartment[j]) <= k){
            ans++, j++;
        }
    }
    cout<<ans<<"\n";
}