#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//Reference: 
//https://www.youtube.com/watch?v=83yW2Pp6HMk
int main(){
    string s;
    cin>>s;
    int n = s.length();
    map<ll, ll> m;
    m[0]++;
    ll sum = 0, ans = 0, pow = 1;
    for(int i = n-1; i >= 0; i--){
        sum = (sum + (pow * (s[i] - '0'))) % 2019;
        if(m.count(sum))
            ans += m[sum];
        m[sum]++;
        pow = (pow* 10) % 2019;
    }
    cout<<ans<<endl;
    return 0;
}
