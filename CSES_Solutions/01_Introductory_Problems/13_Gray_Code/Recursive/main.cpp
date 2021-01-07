#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main() {
    int n;
    cin>>n;
    vector<int> v;
    function<void(int)> solve = [&](int x){
        if(!x){
            for(int c: v){
                cout<<c;
            }
            cout<<endl;
            return 0;
        }
        solve(x-1);
        if(v[x-1])
            v[x-1] = 0;
        else
            v[x-1] = 1;
        solve(x-1);
    };
    
    for(int i = 0; i < n; i++){
        v.push_back(0);
    }
    solve(n);
    
    return 0;
}