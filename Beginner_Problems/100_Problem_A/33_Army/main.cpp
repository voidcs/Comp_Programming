#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    int n;
    cin>>n;
    int req[n-1];
    for(int i = 0; i < n-1; i++)
        cin>>req[i];
    int a, b;
    cin>>a>>b;
    a--, b--;
    int ans = 0;
    for(int i = a; i < b; i++)
        ans += req[i];
    cout<<ans<<endl;
    
    return 0;
}