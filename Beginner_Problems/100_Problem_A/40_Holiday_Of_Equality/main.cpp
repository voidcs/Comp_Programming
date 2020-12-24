#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    int ans = 0;
    sort(a, a + n);
    for(int i = 0; i < n-1; i++){
        ans += (a[n-1] - a[i]);
    }
    cout<<ans<<endl;
    
    return 0;
}