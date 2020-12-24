#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    string a, b;
    cin>>a>>b;
    reverse(a.begin(), a.end());
    if(a == b)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}