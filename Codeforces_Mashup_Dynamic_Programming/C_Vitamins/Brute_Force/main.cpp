#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/gym/302977/problem/C

int main(){
    ll n;
    cin>>n;
    map<string, ll> m;
    vector<string> v;
    char letter[3] = {'A', 'B', 'C'};
    for(int i = 0; i < 1<<3; i++){
        string s;
        for(int j = 0; j < 3; j++){
            if(i & 1<<j)
                s += letter[j];
        }
        sort(s.begin(), s.end());
        v.push_back(s);
        m[s] = INF;
    }
    while(n--){
        ll cost;
        string str;
        cin>>cost>>str;
        sort(str.begin(), str.end());
        m[str] = min(m[str], cost);
        for(int i = 0; i < str.length(); i++){
            string s;
            s += str[i];
            m[s] = min(m[s], cost);
        }
    }
    
    ll ans = INF;
    for(int i = 0; i < 1<<8; i++){
        string s;
        ll sum = 0;
        for(int j = 0; j < 8; j++){
            if(i & 1<<j){
                s += v[j];
                sum += m[v[j]];
            }
        }
        set<char> cnt;
        for(int j = 0; j < s.length(); j++){
            cnt.insert(s[j]);
        }
        if(cnt.size() == 3)
            ans = min(ans, sum);
    }
    if(ans == INF)
        cout<<"-1\n";
    else
        cout<<ans<<endl;
    
    return 0; 
}
