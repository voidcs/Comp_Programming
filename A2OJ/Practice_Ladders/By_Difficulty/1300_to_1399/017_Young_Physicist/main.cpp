#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/contest/69/problem/A

int main(){
    int n, x;
    cin>>n;
    array<int, 3> v = {0, 0 ,0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin>>x;
            v[j] += x;
        }
    }
    if((v[0] | v[1] | v[2]) == 0)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}
