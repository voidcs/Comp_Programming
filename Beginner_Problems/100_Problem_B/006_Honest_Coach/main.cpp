#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/problemset/problem/1360/B

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin>>a[i];
        sort(a, a + n);
        ll ans = INF;
        for(int i = 1; i < n; i++)
            ans = min(ans, (ll)a[i] - a[i-1]);
        cout<<ans<<endl;
        
    }
    return 0;
}