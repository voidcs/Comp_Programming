#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/problemset/problem/1335/B

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, a, b;
        cin>>n>>a>>b;
        for(int i = 0; i < n; i++){
            char c = 'a' + (i % b);
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}