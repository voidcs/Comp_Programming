#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        for(int i = 0; i < n; i++){
            cout<<(char)('a' + (i%k));
        }
        cout<<endl;
    }
    return 0;
}
