#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> elsie(n);
    set<int> s, bessie;
    for(int &x: elsie){
        cin>>x;
        s.insert(x);
    }
    for(int i = 1; i <= 2*n; i++){
        if(!s.count(i))
            bessie.insert(i);
    }
    int ans = 0;
    sort(elsie.begin(), elsie.begin() + n/2, greater<int>());
    sort(elsie.begin() + n/2, elsie.end());
    for(int i = 0; i < n/2; i++){
        auto it = --bessie.end();
        if(*it > elsie[i]){
            ans++;
            bessie.erase(it);
        }
    }
    for(int i = n/2; i < n; i++){
        auto it = bessie.upper_bound(elsie[i]);
        if(it != bessie.begin()){
            it--;
            ans++;
            bessie.erase(it);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
