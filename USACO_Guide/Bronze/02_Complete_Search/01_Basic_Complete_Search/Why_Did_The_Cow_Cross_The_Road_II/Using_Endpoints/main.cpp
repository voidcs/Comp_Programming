#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    string s;
    cin>>s;
    map<char, vector<int>> m;
    for(int i = 0; i < s.length(); i++){
        m[s[i]].push_back(i);
    }
    int ans = 0;
    for(char i = 'A'; i <= 'Z'; i++){
        for(char j = 'A'; j <= 'Z'; j++){
            if(m[i][0] < m[j][0] && m[i][1] > m[j][0] && m[i][1] < m[j][1]){
                ans++;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
