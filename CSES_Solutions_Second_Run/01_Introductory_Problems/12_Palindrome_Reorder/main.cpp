#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    string s;
    cin>>s;
    ll n = s.length();
    map<char, ll> m;
    for(int i = 0; i < n; i++){
        m[s[i]]++;
    }
    ll cnt = 0;
    for(auto x: m){
        if(x.second%2)
            cnt++;
    }
    if(cnt > 1)
        cout<<"NO SOLUTION\n";
    else{
        string ans, mid;
        for(auto x: m){
            if(x.second%2)
                mid = string(x.second, x.first);
            else{
                for(int i = 0; i < x.second/2; i++)
                    ans += x.first;
            }
        }
        string temp = ans;
        reverse(temp.begin(), temp.end());
        ans += mid;
        ans += temp;
        cout<<ans<<endl;
    }
    return 0;
}
