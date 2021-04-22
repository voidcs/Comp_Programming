#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> v(n);
        for(int &x: v)
            cin>>x;
        for(int i = 0; i < n-1; i++){
            int m = min(v[i], k);
            v[i] -= m;
            v[n-1] += m;
            k -= m;
        }
        for(int x: v)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}