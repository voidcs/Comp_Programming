#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> elsie(n), bessie;
    set<int> s;
    for(int &x: elsie){
        cin>>x;
        s.insert(x);
    }
    for(int i = 1; i <= 2*n; i++){
        if(!s.count(i))
            bessie.push_back(i);
    }
    sort(elsie.rbegin(), elsie.rend());
    sort(bessie.rbegin(), bessie.rend());
    int j = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(j < n && elsie[i] < bessie[j]){
            ans++, j++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
