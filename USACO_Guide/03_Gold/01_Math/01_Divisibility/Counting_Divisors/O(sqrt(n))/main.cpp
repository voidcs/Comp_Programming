#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans = 0;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                if(i * i == n)
                    ans++;
                else
                    ans += 2;
            }
        }
        cout << ans << "\n";
    }
}
