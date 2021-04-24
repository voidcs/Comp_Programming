#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/208/A

int main(){
    string s;
    cin>>s;
    int n = s.length();
    bool ok = 0;
    for(int i = 0; i < n; i++){
        if(i+2 < n && s.substr(i, 3) == "WUB"){
            if(ok)
                cout<<" ";
            ok = 0;
            i += 2;
        }
        else{
            cout<<s[i];
            ok = 1;
        }
    }

    return 0;
}