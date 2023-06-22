#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    int n;
    cin>>n;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin>>a>>b>>c;
        pq.push({b, 0, c});
        pq.push({a, 1, c});
    }
    int ans = 0, curr = 0;
    while(!pq.empty()){
        int type = pq.top()[1];
        int c = pq.top()[2];
        pq.pop();
        if(type)
            curr += c;
        else
            curr -= c;
        ans = max(ans, curr);
    }
    cout<<ans<<endl;
    
    return 0;
}