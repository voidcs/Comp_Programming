#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n;
    cin>>n;
    vector<pair<int, int>> a(n);
    
    for(int i = 0; i < n; i++)
        cin>>a[i].first>>a[i].second;
    
    sort(a.begin(), a.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    
    ll ans = 0;
    ll curr = 0;
    for(int i = 0; i < n; i++){
        if(!pq.empty() && pq.top() < a[i].first){
            pq.pop();
            curr--;
        }
        pq.push(a[i].second);
        curr++;
        ans = max(ans, curr);
    }
    cout<<ans<<endl;
    
    return 0;
}