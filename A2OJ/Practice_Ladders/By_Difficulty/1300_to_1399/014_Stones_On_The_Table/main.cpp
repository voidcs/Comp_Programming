#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/contest/266/problem/A

int main(){
    int n;
    string s;
    cin>>n>>s;
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        if(s[i] == s[i+1])
            ans++;
    }
    cout<<ans<<endl;

    return 0;
}