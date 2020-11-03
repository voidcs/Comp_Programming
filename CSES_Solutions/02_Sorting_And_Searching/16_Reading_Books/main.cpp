#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll a[n];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum += a[i];
    }
    sort(a, a + n);
    ll ans = max(sum, 2 * a[n-1]);
    cout<<ans<<endl;
    /*
     * In the case that the last book takes longer to read than the rest of the
     * other books combined, one of the kids will have to wait until the other
     * finishes the longest book, thus creating a bottleneck. This makes the
     * solution 2*max_element. In any other case, they can simply read different
     * books from one another and the answer is simply the sum
    */
    return 0;
}