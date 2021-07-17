#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    vector<vector<int>> p(4, vector<int>(n+1));
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        for(int j = 1; j <= 3; j++){
            p[j][i+1] = p[j][i];
        }
        p[x][i+1] = p[x][i] + 1;
    }
    while(m--){
        int l, r;
        cin>>l>>r;
        for(int i = 1; i <= 3; i++){
            cout<<p[i][r] - p[i][l-1];
            if(i < 3)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
