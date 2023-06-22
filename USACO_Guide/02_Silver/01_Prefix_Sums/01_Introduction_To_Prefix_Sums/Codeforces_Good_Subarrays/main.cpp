#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        map<int, int> m;
        m[0]++;
        ll ans = 0, sum = 0;
        for(int i = 0; i < n; i++){
            sum += s[i]-'0';
            int need = sum-i-1;
            if(m.count(need))
                ans += m[need];
            m[sum-i-1]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}