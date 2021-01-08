#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
bool v[7][7];
ll ans = 0;
string str;

//Note that: 
//Using 2d vector is almost twice as slow as 2d array
//Lambda function runtime is 7 seconds, regular function runtime is 1 second
//Impossible to get AC with lambda

bool valid (int x, int y){
    return (x >= 0 && x < 7 && y >= 0 && y < 7 && !v[x][y]);
}

void dfs (int x, int y, int count){
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
}

int main(){
    //freopen("input1.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>str;
    int n = 7;
    
    dfs(0, 0, 0);
    cout<<ans<<endl;
    
    return 0; 
} 