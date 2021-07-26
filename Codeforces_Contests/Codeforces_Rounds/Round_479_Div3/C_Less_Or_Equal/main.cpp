#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    map<int, int> m;
    for(int &x: v){
        cin>>x;
        m[x]++;
    }
    sort(v.begin(), v.end());
    if(k == 0){
        if(v[0] == 1)
            cout<<"-1\n";
        else
            cout<<"1\n";
        return 0;
    }
    int cnt = 0, ans = -1;
    for(auto x: m){
        if(cnt >= k)
            break;
        cnt += x.second;
        ans = x.first;
    }
    if(cnt == k)
        cout<<ans<<endl;
    else
        cout<<"-1\n";
    return 0;
}