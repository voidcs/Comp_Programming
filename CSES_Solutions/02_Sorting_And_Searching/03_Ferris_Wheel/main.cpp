#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, x;
    cin>>n>>x;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    sort(a, a + n);
    int ans = 0;
    int l = 0, r = n-1;
    int pairs = 0;
    while(l < r){
        if(a[l] + a[r] <= x){
            pairs++;
            l++, r--;
        }
        else{
            r--;
        }
    }
    ans += pairs;
    ans += (n - (pairs*2));
    cout<<ans<<endl;
    
    return 0;
}