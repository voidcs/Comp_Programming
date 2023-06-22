#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int &x: a)
        cin>>x;
    for(int &x: b)
        cin>>x;
    set<int> possible, s;
    for(auto x: b)
        s.insert(x);
    
    int sum = 0;
    for(int j = 0; j < n; j++){
        sum += a[j];
        possible.insert(b[0] - sum);
    }

    int ans = 0;
    for(auto x: possible){
        set<int> have;
        for(int i = 0; i < n; i++){
            x += a[i];
            have.insert(x);
        }
        bool valid = 1;
        for(int i = 0; i < m; i++){
            valid &= (have.count(b[i]));
        }
        if(valid)
            ans++;
    }
    cout<<ans<<endl;
    
    return 0;
}