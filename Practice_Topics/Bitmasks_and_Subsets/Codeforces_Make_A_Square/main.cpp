#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
//problem link
//https://codeforces.com/problemset/problem/962/C

int main(){
    string str;
    cin>>str;
    ll n = str.length();
    ll ans = 1e10;
    for(int i = 0; i < (1<<n); i++){
        string s;
        for(int j = 0; j < n; j++){
            if(i & (1<<j))
                s += str[j];
        }
        if(s.length() == 0)
            continue;
        
        string temp;
        bool flag2 = 0;
        
        for(int j = 0; j < s.length(); j++){
            if(s[j] != '0')
                flag2 = 1;
            if(flag2)
                temp += s[j];
        }
        
        s = temp;
        ll num = 0;
        for(ll j = 0; j < s.length(); j++){
            num += (s[j] - '0') * pow(10, s.length() - 1 - j);
        }
        
        bool flag = 0;
        for(ll j = 1; j*j <= num; j++){
            if(j *j == num)
                flag = 1;
        }
        if(flag){
            ans = min(ans, n - (ll)s.length());
        }
    }
    
    if(ans == 1e10)
        cout<<"-1\n";
    else
        cout<<ans<<endl;
    return 0;
}