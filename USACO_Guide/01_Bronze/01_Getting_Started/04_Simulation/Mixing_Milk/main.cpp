#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int capacity[3];
    int have[3];
    for(int i = 0; i < 3; i++)
        cin>>capacity[i]>>have[i];
    for(int i = 0; i < 100; i++){
        int x = i%3, y = (i+1)%3;
        int r = min(have[x], capacity[y] - have[y]);
        have[y] += r;
        have[x] -= r;
    }
    for(int i = 0; i < 3; i++)
        cout<<have[i]<<endl;
    
    return 0;
}