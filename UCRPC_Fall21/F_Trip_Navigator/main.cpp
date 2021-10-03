#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    ll n, time;
    cin>>n>>time;
    vector<vector<ll>> v(n, vector<ll>(n)), dist(n, vector<ll>(n, INF));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin>>c;
            if(c == '-')
                v[i][j] = 0;
            else
                v[i][j] = 1;
        }
    }
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
    dist[0][0] = 0;
    pq.push({0, 0, 0});
    array<ll, 2> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    auto valid = [&](ll x, ll y){
        return x >= 0 && x < n && y >= 0 && y < n;
    };
    while(pq.size()){
        ll t = pq.top()[0];
        ll x = pq.top()[1];
        ll y = pq.top()[2];
        if(t > dist[x][y])
            continue;
        pq.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(valid(nx, ny) && dist[nx][ny] > t + 1 + (time * v[nx][ny])){
                dist[nx][ny] = dist[x][y] + 1;
                if(v[nx][ny])
                    dist[nx][ny] += time;
                pq.push({dist[nx][ny], nx, ny});
            }
        }
    }
    cout<<dist[n-1][n-1]<<endl;
    return 0;
}