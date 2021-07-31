#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n), p(n+1);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        sum += v[i];
        p[i+1] = sum;
    }
    int a = 0, b = 0;
    auto valid = [&](int d){
        for(int i = d; i <= n; i++){
            if(p[i] - p[i-d] + k >= d){
                a = i-d, b = i-1;
                return true;
            }
        }
        return false;
    };
    int l = 0, r = n;
    int ans = 0, ansl = -1, ansr = -1;
    while(l <= r){
        int m = (l+r)/2;
        if(valid(m)){
            //cout<<m<<" worked\n";
            ans = m;
            ansl = a, ansr = b;
            l = m + 1;
        }
        else{
            r = m - 1;
            //cout<<m<<" didn't work\n";
        }
    }
    cout<<ans<<endl;
    if(ansl != -1){
        for(int i = ansl; i <= ansr; i++){
            v[i] = 1;
        }
    }
    for(auto x: v)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
