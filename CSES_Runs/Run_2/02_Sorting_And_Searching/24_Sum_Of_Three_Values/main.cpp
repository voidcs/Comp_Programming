#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    ll n, x;
    cin>>n>>x;
    array<ll, 2> a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i][0];
        a[i][1] = i;
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        ll need = x - a[i][0];
        ll l = i+1, r = n-1;
        while(l < r){
            if(a[l][0]+a[r][0] > need)
                r--;
            else if(a[l][0]+a[r][0] < need)
                l++;
            else{
                cout<<a[i][1]+1<<" "<<a[l][1]+1<<" "<<a[r][1]+1<<endl;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
    
    return 0;
}