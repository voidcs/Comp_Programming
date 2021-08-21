#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//Start all pointers on the left of the array
//Find the smallest element and then increment it to the right to get a smaller difference
//If the smallest element is at the end of its array, there is nothing else to do, break

int main(){
    vector<ll> sizes(4);
    vector<vector<ll>> v(4);
    for(int i = 0; i < 4; i++){
        cin>>sizes[i];
        v[i].resize(sizes[i]);
        for(ll &x: v[i])
            cin>>x;
    }
    for(int i = 0; i < 4; i++)
        sort(v[i].begin(), v[i].end());
    vector<ll> it(4);
    ll ans = INF;
    vector<ll> best;
    while(1){
        vector<ll> t;
        for(int i = 0; i < 4; i++)
            t.push_back(v[i][it[i]]);
        sort(t.begin(), t.end());
        if(t[3] - t[0] < ans){
            ans = t[3] - t[0];
            t.clear();
            for(int i = 0; i < 4; i++)
                t.push_back(v[i][it[i]]);
            best = t;
        }
        ll smallest = INF, j = -1;
        for(int i = 0; i < 4; i++){
            if(v[i][it[i]] < smallest){
                smallest = v[i][it[i]];
                j = i;
            }
        }
        if(it[j] == sizes[j]-1)
            break;
        else
            it[j]++;
    }
    for(auto x: best)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
