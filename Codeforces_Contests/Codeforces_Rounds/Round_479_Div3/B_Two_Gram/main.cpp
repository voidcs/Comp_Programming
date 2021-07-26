#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    string s;
    cin>>n>>s;
    map<string, int> m;
    for(int i = 0; i < n-1; i++){
        m[s.substr(i, 2)]++;
    }
    int cnt = 0;
    string ans;
    for(auto x: m){
        if(x.second > cnt){
            ans = x.first;
            cnt = x.second;
        }
    }
    cout<<ans<<endl;
    return 0;
}
