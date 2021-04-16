#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/270/A

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(360 % (180-n) == 0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

 