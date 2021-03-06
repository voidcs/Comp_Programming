#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    //freopen("input.txt", "r", stdin);
    string s;
    getline(cin, s);
    set<char> ans;
    for(int i = 0; i < s.length(); i++){
        if(isalpha(s[i]))
            ans.insert(s[i]);
    }
    cout<<ans.size()<<endl;
    
    return 0;
}