#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    int ans = 0;
    for(int i = 1; i < n-1; i++){
        if(v[i] == 0 && v[i-1] + v[i+1] == 2){
            ans++;
            v[i+1] = 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
