#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--){
        string a, b;
        cin>>a>>b;
        int n = a.length(), m = b.length();
        int ans = 0;
        for(int len = 1; len <= min(n, m); len++){
            for(int i = 0; i+len <= n; i++){
                for(int j = 0; j+len <= m; j++){
                    if(a.substr(i, len) == b.substr(j, len))
                        ans = max(ans, len);
                }
            }
        }
        cout<<(n+m) - (2*ans)<<endl;
    }
    return 0;
}