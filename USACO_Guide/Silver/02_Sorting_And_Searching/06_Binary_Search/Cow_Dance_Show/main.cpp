#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    int n, t;
    cin>>n>>t;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    auto valid = [&](int m){
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        while(i < n && pq.size() < m){
            pq.push(v[i++]);
        }
        int last = 0;
        while(pq.size()){
            int time = pq.top();
            last = max(last, time);
            pq.pop();
            if(i < n){
                pq.push(time + v[i++]);
            }
        }
        return last <= t;
    };
    int l = 0, r = 1e9, ans = -1;
    while(l <= r){
        int m = (l+r)/2;
        if(valid(m)){
            ans = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    cout<<ans<<"\n";
} 
