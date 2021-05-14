#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n;
    cin>>n;
    vector<array<int, 2>> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i][0]>>v[i][1];
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(v[i][0] == v[j][0] && v[j][1] == v[k][1]){
                    ans = max(ans, abs(v[j][0] - v[k][0]) * abs(v[i][1] - v[j][1]));
                }
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
