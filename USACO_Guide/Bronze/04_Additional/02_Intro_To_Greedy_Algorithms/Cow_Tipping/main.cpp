#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin>>c;
            v[i][j] = c - '0';
        }
    }
    auto check = [&](){
        int sum = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                sum += v[i][j];
        return sum == 0;
    };
    int ans = 0;
    while(!check()){
        ans++;
        int x = -1, y = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(v[i][j])
                    x = i, y = j;
            }
        }
        for(int i = 0; i <= x; i++){
            for(int j = 0; j <= y; j++){
                v[i][j] = !v[i][j];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
