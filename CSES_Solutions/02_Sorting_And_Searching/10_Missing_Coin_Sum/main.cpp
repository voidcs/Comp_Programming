#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
//REFERENCE
//https://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    //Initialize first answer to 1
    ll ans = 1;
    sort(a, a + n);
    /*
     * if a[i] > ans, then we have found a gap and this is the smallest sum
     * that cannot be made with a subset of the array
     * 
     * if a[i] <= ans then we increment ans by a[i] since we already could've
     * made all the sums at value ans+a[i] and lower
    */
    for(int i = 0; i < n; i++){
        if(a[i] <= ans)
            ans += a[i];
    }
    cout<<ans<<endl;
    
    return 0;
}