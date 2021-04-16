#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/282/A

int main(){
    int n;
    cin>>n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        if(s[1] == '+')
            ans++;
        else
            ans--;
    }
    cout<<ans<<endl;
    return 0;
}
 