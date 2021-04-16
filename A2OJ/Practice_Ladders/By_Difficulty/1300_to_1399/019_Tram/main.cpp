#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/116/A
int main(){
    int n;
    cin>>n;
    int ans = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        int x, y;
        cin>>x>>y;
        cnt += y-x;
        ans = max(ans, cnt);
    }
    cout<<ans<<endl;

    return 0;
}
