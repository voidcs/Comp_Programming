#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            if(i <= j)
                sum += v[j] * (j-i);
            else
                sum += v[j] * (j + 1 + (n - 1 - i));
        }
        ans = min(ans, sum);
    }
    cout<<ans<<endl;
    
    return 0;
}