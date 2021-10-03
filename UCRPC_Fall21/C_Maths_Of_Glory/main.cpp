#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin>>n>>m;
    int a = n, b = n;
    int ans = 1;
    for(int i = 0; i < m; i++){
        vector<int> v(4);
        for(int &x: v)
            cin>>x;
        int x = v[0] * v[1];
        int y = v[2] * v[3];
        a -= y; b -= x;
        if(a <= 0 && b <= 0){
            cout<<"It's a tie at round "<<ans<<"!\n";
            return 0;
        }
        else if(a <= 0){
            cout<<"Team 2 wins at round "<<ans<<"!\n";
            return 0;
        }
        else if(b <= 0){
            cout<<"Team 1 wins at round "<<ans<<"!\n";
            return 0;
        }
        ans++;
    }
    cout<<"Oh no!\n";
    return 0;
}