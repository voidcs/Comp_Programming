#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n, x;
    cin>>n>>x;
    ll a[n];
    map<int, int> m;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        m[a[i]] = i+1;
    }

    for(int i = 0; i < n; i++){
        int need = x-a[i];
        if(m.count(need) && m[need] != i+1){
            cout<<m[need]<<" "<<i+1<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}