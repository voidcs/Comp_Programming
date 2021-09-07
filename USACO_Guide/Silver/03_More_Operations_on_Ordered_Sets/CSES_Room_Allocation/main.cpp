#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<array<int, 3>> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i][0]>>v[i][1];
        v[i][2] = i;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    vector<int> ans2(n);
    set<int> avail;
    map<int, int> m;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    for(int i = 0; i < n; i++){
        pq.push({v[i][0], 0, v[i][2]});
        pq.push({v[i][1], 1, v[i][2]});
    }
    while(pq.size()){
        int leave = pq.top()[1];
        int t = pq.top()[0];
        int id = pq.top()[2];
        pq.pop();
        if(leave){
            avail.insert(m[id]);
            m.erase(id);
        }
        else{
            if(avail.size()){
                int x = *avail.begin();
                ans2[id] = x;
                m[id] = x;
                avail.erase(x);
            }
            else{
                ans++;
                int room = m.size() + 1;
                m[id] = room;
                ans2[id] = room;
            }
        }
    }
    cout<<ans<<endl;
    for(auto x: ans2)
        cout<<x<<" ";
    return 0;
}
