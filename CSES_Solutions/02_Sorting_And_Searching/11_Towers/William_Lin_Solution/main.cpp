#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    vector<int> v;
    
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        int index = upper_bound(v.begin(), v.end(), x) - v.begin();
        if(index == v.size())
            v.push_back(x);
        else
            v[index] = x;
    }
    cout<<v.size()<<endl;
    
    return 0;
}