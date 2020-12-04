#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string str;
    cin>>str;
    ll cnt = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '7' || str[i] == '4')
            cnt++;
    }
    string s = to_string(cnt);
    for(int i = 0; i < s.length(); i++){
        if(s[i] != '7' && s[i] != '4'){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}