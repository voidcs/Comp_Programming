#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int n;
    cin>>n;
    string a, b;
    cin>>a>>b;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            ans++;
            while(i < n && a[i] != b[i]){
                i++;
            }
            i--;
        }
    }
    cout<<ans<<endl;

    return 0; 
} 
