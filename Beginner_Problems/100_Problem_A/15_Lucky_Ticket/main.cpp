#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n;
    string str;
    cin>>n>>str;
    bool flag = 1;
    for(int i = 0; i < n; i++){
        if(str[i] != '4' && str[i] != '7')
            flag = 0;
    }
    ll s1 = 0, s2 = 0;
    for(int i = 0; i < n; i++){
        if(i < n/2)
            s1 += str[i] - '0';
        else
            s2 += str[i] - '0';
    }
    flag &= (s1 == s2);
    if(flag)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}