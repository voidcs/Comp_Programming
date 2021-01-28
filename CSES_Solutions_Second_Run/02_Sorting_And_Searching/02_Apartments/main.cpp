#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    int a[n], b[m];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for(int i = 0; i < m; i++)
        cin>>b[i];
    sort(a, a + n);
    sort(b, b + m);
    int ans = 0, j = 0;
    for(int i = 0; i < n; i++){
        while(j < m && b[j] + k < a[i]){
            j++;
        }
        if(abs(b[j]-a[i]) <= k){
            ans++;
            j++;
        }
        if(j >= m)
            break;
    }
    cout<<ans<<endl;  
    
    return 0;
}