#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    vector<int> v(5);
    v[2] = 1;
    int n;
    cin>>n;
    while(n--){
        int x, y;
        cin>>x>>y;
        x--, y--;
        swap(v[x], v[y]);
    }
    int ans = -1;
    for(int i = 0; i < 5; i++){
        if(v[i])
            ans = i+1;
    }
    cout<<ans<<endl;
    return 0;
}
