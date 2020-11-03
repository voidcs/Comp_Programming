#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, x;
    cin>>n>>x;
    array<ll, 2> a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i][0];
        a[i][1] = i;
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        ll goal = x - a[i][0];
        ll l = i+1, r = n-1;
        while(l < r){
            if(a[l][0] + a[r][0] < goal)
                l++;
            else if(a[l][0] + a[r][0] > goal)
                r--;
            else{
                cout<<a[i][1]+1<<" "<<a[l][1]+1<<" "<<a[r][1]+1<<endl;
                return 0;
            }
        }
    }
    
    cout<<"IMPOSSIBLE\n";
    return 0;
}