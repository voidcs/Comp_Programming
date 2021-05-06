#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    vector<vector<int>> vis(600, vector<int>(600, 0));
    int x = -1, y = -5;
    x += 300, y += 300;
    vis[x][y] = 1;
    for(int i = 0; i < 2; i++){
        y--;
        vis[x][y] = 1;
    }
    for(int i = 0; i < 8; i++){
        x++;
        vis[x][y] = 1;
    }
    for(int i = 0; i < 4; i++){
        y++;
        vis[x][y] = 1;
    }
    for(int i = 0; i < 2; i++){
        x--;
        vis[x][y] = 1;
    }
    for(int i = 0; i < 2; i++){
        y--;
        vis[x][y] = 1;
    }
    for(int i = 0; i < 2; i++){
        x--;
        vis[x][y] = 1;
    }
    for(int i = 0; i < 2; i++){
        y++;
        vis[x][y] = 1;
    }
    for(int i = 0; i < 3; i++){
        x--;
        vis[x][y] = 1;
    }
    for(int i = 0; i < 2; i++){
        y++;
        vis[x][y] = 1;
    }
    x = -1 + 300, y = -5 + 300;
    char d;
    cin>>d;
    while(d != 'q'){
        int n;
        cin>>n;
        bool valid = 1;
        if(d == 'l'){
            for(int i = 0; i < n; i++){
                x--;
                if(vis[x][y])
                    valid = 0;
                vis[x][y] = 1;
            }
        }
        if(d == 'r'){
            for(int i = 0; i < n; i++){
                x++;
                if(vis[x][y])
                    valid = 0;
                vis[x][y] = 1;
            }
        }
        if(d == 'u'){
            for(int i = 0; i < n; i++){
                y++;
                if(vis[x][y])
                    valid = 0;
                vis[x][y] = 1;
            }
        }
        if(d == 'd'){
            for(int i = 0; i < n; i++){
                y--;
                if(vis[x][y])
                    valid = 0;
                vis[x][y] = 1;
            }
        }
        cout<<x-300<<" "<<y-300<<" ";
        if(valid)
            cout<<"safe\n";
        else{
            cout<<"DANGER\n";
            break;
        }
        cin>>d;
    }
    return 0;
}