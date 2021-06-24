#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    string s;
    cin>>n>>s;
    int ans = 0;
    string x = "RGB";
    for(int i = 1; i < n-1; i++){
        if(s[i] == s[i-1]){
            ans++;
            for(int j = 0; j < 3; j++){
                s[i] = x[j];
                if(s[i] != s[i-1] && s[i] != s[i+1])
                    break;
            }
        }
    }
    if(s[n-1] == s[n-2]){
        for(int i = 0; i < 3; i++){
            s[n-1] = x[i];
            if(x[i] != s[n-2])
                break;
        }
        ans++;
    }
    cout<<ans<<endl;
    cout<<s<<endl;
    return 0;
}