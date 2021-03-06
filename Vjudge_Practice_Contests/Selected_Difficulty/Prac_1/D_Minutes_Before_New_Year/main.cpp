#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int time = 24*60;
        int a, b;
        cin>>a>>b;
        int curr = (a*60) + b;
        cout<<time - curr<<endl;
    }
    
    return 0;
}