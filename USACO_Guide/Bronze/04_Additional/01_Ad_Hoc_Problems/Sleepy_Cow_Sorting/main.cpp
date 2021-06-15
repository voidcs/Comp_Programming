#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e9;

int main(){
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    for(int i = 0; i < n; i++){
        if(is_sorted(v.begin()+i, v.end())){
            cout<<i<<endl;
            return 0;
        }
    }
    
    return 0;
}