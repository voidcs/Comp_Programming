#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n;
    string s;
    cin>>n>>s;
    int ans = 0;
    while(1){
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < 3; j++){
                if(i+j < n && s[i+j] == 'x')
                    cnt++;
            }
            if(cnt == 3){
                s.erase(i+2, 1);
                ans++;
                break;
            }
        }
        if(s.find("xxx") == string::npos)
            break;
    }
    cout<<ans<<endl;
    return 0;
}
