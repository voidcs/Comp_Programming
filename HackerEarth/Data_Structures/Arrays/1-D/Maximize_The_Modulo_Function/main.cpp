#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/maximize-modulo-2-0cb15ded/

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--){
        ll n, k;
        string s;
        cin>>n>>k>>s;
        auto expo_pow = [&](ll a, ll pow){
            ll res = 1;
            while(pow){
                if(pow%2)
                    res = (res * a) % k;
                a = (a * a) % k;
                pow /= 2;
            }
            return res;
        };
        ll sum = 0;
        for(int i = n-1; i >= 0; i--){
            ll p = expo_pow(10, n - i - 1);
            ll x = ((s[i] - '0') * p) % k;
            sum = (sum + x) % k;
        }
        ll ans = sum;
        for(int i = 0; i < n; i++){
            ll d = s[i] - '0';
            ll r = (d * expo_pow(10, n - i - 1)) % k;
            sum = (sum - r + k) % k;
            ans = max(ans, sum);
            r = (d * expo_pow(10, n - i - 2)) % k;
            sum = (sum + r) % k;
        }
        cout<<ans<<endl;
    }
    return 0;
}