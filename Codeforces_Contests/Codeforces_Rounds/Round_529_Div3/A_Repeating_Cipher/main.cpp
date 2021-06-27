#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    string s;
    cin>>n>>s;
    string ans;
    int d = 0;
    for(int i = 0; i < n; i++){
        ans += s[i];
        i += d++;
    }
    cout<<ans<<endl;
    return 0;
}
