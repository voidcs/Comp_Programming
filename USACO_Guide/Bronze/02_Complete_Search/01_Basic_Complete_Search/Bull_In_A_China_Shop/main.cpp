#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("bcs.in", "r", stdin);
    freopen("bcs.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    vector<vector<char>> key(n, vector<char>(n));
    vector<vector<vector<char>>> v(m, vector<vector<char>>(n, vector<char>(n)));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>key[i][j];
    vector<vector<array<int, 2>>> pieces;
    for(int i = 0; i < m; i++){
        vector<array<int, 2>> t;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                char c;
                cin>>c;
                if(c == '#')
                    t.push_back({j, k});
            }
        }
        pieces.push_back(t);
    }

    auto valid = [&](int x, int y){
        return x >= 0 && x < n && y >= 0 && y < n;
    };
    int ansX = -1, ansY = -1;
    for(int a = 0; a < m; a++){
        for(int b = a + 1; b < m; b++){
            for(int ax = 0; ax < n; ax++){
                for(int ay = 0; ay < n; ay++){
                    for(int bx = 0; bx < n; bx++){
                        for(int by = 0; by < n; by++){
                            vector<vector<char>> merge(n, vector<char>(n, '.'));
                            bool ok = 1;
                            if(ax == bx && ay == by)
                                continue;
                            vector<array<int, 2>> pieceOne = pieces[a];
                            vector<array<int, 2>> pieceTwo = pieces[b];
                            merge[ax][ay] = '#';
                            merge[bx][by] = '#';
                            for(int i = 1; i < pieceOne.size(); i++){
                                int x = ax + (pieceOne[i][0] - pieceOne[0][0]);
                                int y = ay + (pieceOne[i][1] - pieceOne[0][1]);
                                if(valid(x, y) && merge[x][y] == '.')
                                    merge[x][y] = '#';
                                else
                                    ok = 0;
                            }
                            for(int i = 1; i < pieceTwo.size(); i++){
                                int x = bx + (pieceTwo[i][0] - pieceTwo[0][0]);
                                int y = by + (pieceTwo[i][1] - pieceTwo[0][1]);
                                if(valid(x, y) && merge[x][y] == '.')
                                    merge[x][y] = '#';
                                else
                                    ok = 0;
                            }
                            if(!ok)
                                continue;
                            if(merge == key)
                                ansX = a, ansY = b;
                        }
                    }
                }
            }
        }
    }
    cout<<ansX+ 1<<" "<<ansY+1<<endl;
    
    return 0;
}
