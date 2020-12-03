#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n, k, l, c, d, p, nl, np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    ll have = k * l;
    c *= d;
    ll total = min({have/nl, c, p/np});
    cout<<total/n<<endl;
    return 0;
}