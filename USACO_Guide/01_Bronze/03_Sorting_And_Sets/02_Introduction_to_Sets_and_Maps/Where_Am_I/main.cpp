#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int n;
    string s;
    cin>>n>>s;
    for(int i = 1; i < n; i++){
        bool valid = 1;
        set<string> have;
        for(int j = 0; j < n-i+1; j++){
            string x = s.substr(j, i);
            if(have.count(x))
                valid = 0;
            have.insert(x);
        }
        if(valid){
            cout<<i<<endl;
            return 0;
        }
    }
    
    return 0;
}