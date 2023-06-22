#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    int n;
    cin>>n;
    vector<set<string>> have(n);
    for(int i = 0; i < n; i++){
        string s;
        int k;
        cin>>s>>k;
        for(int j = 0; j < k; j++){
            cin>>s;
            have[i].insert(s);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int cnt = 1;
            if(i == j)
                continue;
            for(auto x: have[i]){
                if(have[j].count(x))
                    cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    cout<<ans<<endl;

    return 0;
}
