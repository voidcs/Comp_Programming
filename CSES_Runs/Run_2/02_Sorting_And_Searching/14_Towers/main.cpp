#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    vector<int> v;
    for(int i = 0; i < n; i++){
        int index = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
        if(index == v.size())
            v.push_back(a[i]);
        else
            v[index] = a[i];
    }
    cout<<v.size()<<endl;
    return 0;
}