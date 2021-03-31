#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin>>a[i];
        array<int, 3> cnt = {0, 0, 0};
        for(int i = 0; i < n; i++)
            cnt[a[i]%3]++;
        int r = n/3;
        int ans = 0;
        for(int j = 0; j < 2; j++){
            for(int i = 0; i < 3; i++){
                if(cnt[i] > r){
                    ans += cnt[i] - r;
                    cnt[(i+1)%3] += cnt[i] - r;
                    cnt[i] = r;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}