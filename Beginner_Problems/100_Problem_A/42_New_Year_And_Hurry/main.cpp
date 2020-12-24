#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n, k;
    cin>>n>>k;
    ll t = 240 - k;
    ll sum = 0, ans = 0;
    for(int i = 1; sum + (5*i) <= t; i++){
        ans++;
        sum += 5*i;
    }
    cout<<min(n, ans)<<endl;
    return 0;
}