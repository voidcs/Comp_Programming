#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int n, maxCoor;
    cin>>n>>maxCoor;
    vector<array<int, 2>> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i][0]>>v[i][1];
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x = v[i][0] + 1;
            int y = v[j][1] + 1;
            vector<int> quadrant(4);
            for(int k = 0; k < n; k++){
                if(v[k][0] > x && v[k][1] > y)
                    quadrant[0]++;
                if(v[k][0] < x && v[k][1] > y)
                    quadrant[1]++;
                if(v[k][0] < x && v[k][1] < y)
                    quadrant[2]++;
                if(v[k][0] > x && v[k][1] < y)
                    quadrant[3]++;
            }
            int m = 0;
            for(int k = 0; k < 4; k++)
                m = max(m, quadrant[k]);
            ans = min(ans, m);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}