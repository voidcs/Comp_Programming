#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("stacking.in", "r", stdin);
    freopen("stacking.out", "w", stdout);
    int n, k;
    cin>>n>>k;
    vector<int> p(n+1), v(n);
    for(int i = 0; i < k; i++){
        int l, r;
        cin>>l>>r;
        p[l-1]++, p[r]--;
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += p[i];
        v[i] = sum;
    }
    sort(v.begin(), v.end());
    cout<<v[n/2]<<endl;
    return 0;
}
