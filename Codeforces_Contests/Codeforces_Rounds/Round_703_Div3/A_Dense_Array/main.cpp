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
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            int x = a[i], y = a[i+1];
            if(x >= y)
                swap(x, y);
            while(x*2 < y){
                ans++;
                x *= 2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}