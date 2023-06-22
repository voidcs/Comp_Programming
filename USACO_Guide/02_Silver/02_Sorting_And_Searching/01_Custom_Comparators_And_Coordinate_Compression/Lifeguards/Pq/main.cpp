#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n;
    cin>>n;
    vector<array<int, 2>> v(n);
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    for(auto &x: v){
        cin>>x[0]>>x[1];
    }
    for(int i = 0; i < n; i++){
        pq.push({v[i][0], 1, i});
        pq.push({v[i][1], 0, i});
    }
    vector<int> alone(n);
    set<int> active;
    int prev = 0, total = 0;
    while(pq.size()){
        int time = pq.top()[0];
        int isStart = pq.top()[1];
        int id = pq.top()[2];
        pq.pop();
        if(active.size() > 0)
            total += time - prev;
        if(active.size() == 1){
            alone[*active.begin()] += time - prev;
        }
        if(isStart){
            active.insert(id);
        }
        else if(!isStart){
            active.erase(id);
        }
        prev = time;
    }
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        ans = min(ans, alone[i]);
    }
    cout<<total - ans<<"\n";
}
