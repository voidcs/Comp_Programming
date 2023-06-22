#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>v[i][j];
    array<int, 2> ans = {0, 0}; 
    for(int i = 0; i < n; i++){
        array<int, 2> add = {0, 0};
        for(int j = 0; j < n; j += 2)
            add[0] += v[i][j];
        for(int j = 1; j < n; j += 2){
            add[1] += v[i][j];
        }
        ans[0] += max(add[0], add[1]);
    }
    for(int i = 0; i < n; i++){
        array<int, 2> add = {0, 0};
        for(int j = 0; j < n; j += 2){
            add[0] += v[j][i];
        }
        for(int j = 1; j < n; j += 2){
            add[1] += v[j][i];
        }
        ans[1] += max(add[0], add[1]);
    }
    cout<<max(ans[0], ans[1])<<endl;
    return 0;
}
