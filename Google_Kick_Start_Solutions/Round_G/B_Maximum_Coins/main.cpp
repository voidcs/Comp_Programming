#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://codingcompetitions.withgoogle.com/kickstart/round/00000000001a0069

int main(){
    int c = 1;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll a[n][n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin>>a[i][j];
        map<int, ll> m;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                m[i-j] += a[i][j];
        
        ll ans = -1;
        for(auto x: m)
            ans = max(ans, x.second);
        cout<<"Case #"<<c++<<": "<<ans<<endl;
    }
    
    return 0;
}