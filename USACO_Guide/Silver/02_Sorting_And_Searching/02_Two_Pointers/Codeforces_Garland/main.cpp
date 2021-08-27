//https://codeforces.com/problemset/problem/814/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    string s;
    cin>>n>>s;
    vector<vector<int>> ans(26, vector<int> (n+1));
    for(char c = 'a'; c <= 'z'; c++){
        for(int fill = 0; fill <= n; fill++){
            int most = 0, l = 0, cnt = 0;
            for(int r = 0; r < n; r++){
                if(s[r] == c)
                    cnt++;
                while(cnt + fill < r - l + 1){
                    if(s[l] == c)
                        cnt--;
                    l++;
                }
                most = max(most, r - l + 1);
            }
            ans[c-'a'][fill] = most;
        }
    }
    int t;
    cin>>t;
    while(t--){
        int m;
        char c;
        cin>>m>>c;
        cout<<ans[c-'a'][m]<<endl;
    }
    return 0;
}
