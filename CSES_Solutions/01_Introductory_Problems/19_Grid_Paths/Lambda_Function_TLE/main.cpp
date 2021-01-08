#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
int main(){
    //freopen("input1.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string str;
    cin>>str;
    int n = 7;
    ll ans = 0;
    
    bool v[7][7];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            v[i][j] = 0;
    function<bool(int, int)> valid = [&](int x, int y){
        return (x >= 0 && x < n && y >= 0 && y < n && !v[x][y]);
    };
 
    function<void(int, int, int)> dfs = [&](int x, int y, int count){
        if(x == 6 && y == 0){
            if(count == 48)
                ans++;
            return;
        }
 
        v[x][y] = 1;
        if(str[count] == 'U' || str[count] == '?'){
            if(valid(x-1, y) && !(!valid(x-2, y) && valid(x-1, y+1) && valid(x-1, y-1))){
                dfs(x-1, y, count+1);
            }
        }
        if(str[count] == 'D' || str[count] == '?'){
            if(valid(x+1, y) && !(!valid(x+2, y) && valid(x+1, y+1) && valid(x+1, y-1))){
                dfs(x+1, y, count+1);
            }
        }
        if(str[count] == 'L' || str[count] == '?'){
            if(valid(x, y-1) && !(!valid(x, y-2) && valid(x+1, y-1) && valid(x-1, y-1))){
                dfs(x, y-1, count+1);
            }
        }
        if(str[count] == 'R' || str[count] == '?'){
            if(valid(x, y+1) && !(!valid(x, y+2) && valid(x-1, y+1) && valid(x+1, y+1))){
                dfs(x, y+1, count+1);
            }
        }
        v[x][y] = 0;
        
    };
 
    dfs(0, 0, 0);
    cout<<ans<<endl;
    
    return 0; 
} 