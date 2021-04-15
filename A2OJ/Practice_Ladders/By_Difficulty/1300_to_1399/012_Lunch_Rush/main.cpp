#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/276/A

int main(){
    int n, k;
    cin>>n>>k;
    int ans = -INT_MAX;
    for(int i = 0; i < n; i++){
        int f, t;
        cin>>f>>t;
        if(t <= k)
            ans = max(ans, f);
        else
            ans = max(ans, f-(t-k));
    }
    if(ans == -INT_MAX)
        cout<<"-1\n";
    else
        cout<<ans<<endl;
    return 0;
}

