#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    stack<array<ll, 2>> s;
    for(int i = 0; i < n; i++){
        while(!s.empty() && a[i] <= s.top()[0])
            s.pop();
        if(s.empty())
            cout<<"0 ";
        else
            cout<<s.top()[1]+1<<" ";
        s.push({a[i], i});
    }
    return 0;
}