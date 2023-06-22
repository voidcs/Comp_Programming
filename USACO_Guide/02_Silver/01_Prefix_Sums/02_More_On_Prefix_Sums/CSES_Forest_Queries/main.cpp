#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> p(n+1, vector<int>(n+1));
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            char c;
            cin>>c;
            if(c == '*')
                sum++;
            p[i+1][j+1] = sum + p[i][j+1];
        }
    }
    while(m--){
        int y1, x1, y2, x2;
        cin>>y1>>x1>>y2>>x2;
        cout<<p[y2][x2] - p[y2][x1-1] - p[y1-1][x2] + p[y1-1][x1-1]<<endl;
    }
    return 0;
}
