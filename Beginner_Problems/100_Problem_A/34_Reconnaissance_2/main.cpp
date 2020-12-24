#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    int ans = 0, diff = 1e8;
    for(int i = 0; i < n; i++){
        int x = i, y = (i+1)%n;
        if(abs(a[y]-a[x]) < diff){
            diff = abs(a[y]-a[x]);
            ans = i+1;
        }
    }
    if(ans == n)
        cout<<n<<" "<<1<<endl;
    else
        cout<<ans<<" "<<ans+1<<endl;
    
    return 0;
}