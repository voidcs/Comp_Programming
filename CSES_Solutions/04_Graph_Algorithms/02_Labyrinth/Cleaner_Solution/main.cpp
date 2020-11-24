#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
array<int, 2> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char dir2[4] = {'D', 'R', 'U', 'L'};

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<int>> dx(n, vector<int>(m, -1));
    int startX, startY, endX, endY;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
            if(a[i][j] == 'A')
                startX = i, startY = j;
            if(a[i][j] == 'B')
                endX = i, endY = j;
        }
    }
    
    function<bool(int, int)> valid = [&](int x, int y){
        return(x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '#');
    };

    queue<array<int, 2>> q;
    q.push({startX, startY});
    bool flag = 0;
    while(!q.empty()){
        int x = q.front()[0], y = q.front()[1];
        q.pop();
        for(int i = 0; i < 4; i++){
            int newX = x + dir[i][0];
            int newY = y + dir[i][1];
            if(valid(newX, newY)){
                q.push({newX, newY});
                a[newX][newY] = '#';
                dx[newX][newY] = i;
            }
        }
    }
    
    if(dx[endX][endY] != -1){
        cout<<"YES\n";
        string ans;
        while(startX != endX || startY != endY){
            int d = dx[endX][endY];
            ans += dir2[d];
            //Subtract the direction took to get here in order to backtrack
            endX -= dir[d][0];
            endY -= dir[d][1];
        }
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<endl<<ans<<endl;
    }
    else
        cout<<"NO\n";
    
	
    return 0;
}