#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    string s, p;
    cin>>s>>p;
    s = p + "#" + s;
    int n = s.length();
    vector<int> pi(n);
    for(int i = 1; i < n; i++){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    int ans = 0;
    for(int i = p.length(); i < n; i++){
        if(pi[i] == p.length())
            ans++;
    }
    cout<<ans<<endl;
    
    return 0;
}