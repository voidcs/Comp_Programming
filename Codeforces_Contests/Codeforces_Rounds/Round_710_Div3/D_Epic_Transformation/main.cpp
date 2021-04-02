#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int, int> m;
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            m[x]++;
        }
        priority_queue<array<int, 2>> pq;
        for(auto x: m){
            pq.push({x.second, x.first});
        }
        int pairsUsed = 0;
        while(pq.size() > 1){
            pairsUsed++;
            array<int, 2> a = pq.top();
            pq.pop();
            array<int, 2> b = pq.top();
            pq.pop();
            a[0]--, b[0]--;
            if(a[0])
                pq.push(a);
            if(b[0])
                pq.push(b);
        }
        cout<<n - (pairsUsed*2)<<endl;
    }
    return 0;
}