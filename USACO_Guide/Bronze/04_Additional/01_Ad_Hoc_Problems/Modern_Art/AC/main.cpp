#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e9;

int main(){
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    int n;
    cin>>n;
    vector<vector<int>> g(n, vector<int>(n));
    set<int> s;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin>>c;
            g[i][j] = c - '0';
            s.insert(g[i][j]);
        }
    }
    auto isOnTop = [&](int x, int y){
        int top = n, left = n, bottom = 0, right = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j] == y){
                    top = min(top, i);
                    bottom = max(bottom, i);
                    left = min(left, j);
                    right = max(right, j);
                }
            }
        }
        for(int i = top; i <= bottom; i++){
            for(int j = left; j <= right; j++){
                if(g[i][j] == x)
                    return true;
            }
        }
        return false;
    };
    int ans = 0;
    for(int i = 1; i <= 9; i++){
        if(!s.count(i))
            continue;
        bool isBelow = 1;
        for(int j = 1; j <= 9; j++){
            if(!s.count(j) || i == j)
                continue;
            isBelow &= (!isOnTop(i, j));
        }
        if(isBelow)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}