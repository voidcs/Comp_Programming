#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/contest/1373/problem/B

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int a = 0, b = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i]=='1')
                a++;
            else
                b++;
        }
        int ans = min(a, b);
        if(ans%2)
            cout<<"DA\n";
        else
            cout<<"NET\n";
    }
    return 0;
}