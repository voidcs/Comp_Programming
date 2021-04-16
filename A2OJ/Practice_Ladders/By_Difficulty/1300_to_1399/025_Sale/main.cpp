#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/34/B

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < m; i++){
        if(v[i] < 0)
            ans += v[i]*-1;
    }
    cout<<ans<<endl;
    return 0;
}

 