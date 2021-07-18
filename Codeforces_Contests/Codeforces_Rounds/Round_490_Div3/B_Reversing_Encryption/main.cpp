#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);
    int n;
    string s;
    cin>>n>>s;
    for(int i = 0; i < n; i++){
        if(n % (i+1) == 0){
            reverse(s.begin(), s.begin()+i+1);
        }
    }
    cout<<s<<endl;
    return 0;
}
