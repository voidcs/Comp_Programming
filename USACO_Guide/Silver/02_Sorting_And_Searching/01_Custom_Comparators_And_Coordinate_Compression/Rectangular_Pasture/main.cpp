#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n;
    cin>>n;
    vector<array<int, 2>> v(n);
    for(auto &x: v)
        cin>>x[0]>>x[1];
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
        v[i][0] = i+1;
    sort(v.begin(), v.end(), [&](array<int, 2> a, array<int, 2> b){
            return a[1] < b[1];
    });
    for(int i = 0; i < n; i++)
        v[i][1] = i+1;
    vector<vector<int>> p(n+1, vector<int>(n+1));
    for(auto &x: v){
        p[x[0]][x[1]]++;
    }
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += p[i+1][j+1];
            p[i+1][j+1] = sum;
            p[i+1][j+1] += p[i][j+1];
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            array<int, 2> bottom = {max(v[i][0], v[j][0]), max(v[i][1], v[j][1])};
            array<int, 2> top = {min(v[i][0], v[j][0]), min(v[i][1], v[j][1])};
            ll below = p[top[0]][bottom[1]] - p[top[0]][top[1]-1];
            ll above = p[n][bottom[1]] - p[bottom[0]-1][bottom[1]] - p[n][top[1]-1] + p[bottom[0]-1][top[1]-1];
            ans += below * above;
        }
    }
    cout<<ans + n + 1<<"\n";
    return 0;
}
