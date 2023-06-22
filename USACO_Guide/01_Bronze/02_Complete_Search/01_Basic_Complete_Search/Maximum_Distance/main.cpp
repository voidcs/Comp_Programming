#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n;
    cin>>n;
    int x[n], y[n];
    for(int i = 0; i < n; i++)
        cin>>x[i];
    for(int i = 0; i < n; i++)
        cin>>y[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int a = x[i] - x[j];
            int b = y[i] - y[j];
            ans = max(ans, (a*a) + (b*b));
        }
    }
    cout<<ans<<endl;
    
    return 0;
}