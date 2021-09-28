#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    int n;
    set<int> s;
    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<endl;
    return 0;
}