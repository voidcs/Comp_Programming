#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int n, k, b;
    cin>>n>>k>>b;
    vector<int> v(b);
    for(int i = 0; i < b; i++)
        cin>>v[i];
    sort(v.begin(), v.end());
    int j = 0;
    while(j < b && v[j] <= k)
        j++;
    int ans = j;
    for(int i = 0; i < b; i++){
        if(v[i] + k > n)
            break;
        while(j < b && v[j] <= v[i] + k)
            j++;
        ans = min(ans, j - i - 1);
    }
    cout<<ans<<endl;
    return 0;
}
