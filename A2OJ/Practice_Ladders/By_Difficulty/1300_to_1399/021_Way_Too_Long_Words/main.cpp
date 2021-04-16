#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/contest/71/problem/A

int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(s.length() <= 10)
            cout<<s<<endl;
        else
            cout<<s[0]<<s.length()-2<<s[s.length()-1]<<endl;
    }
    return 0;
}
 