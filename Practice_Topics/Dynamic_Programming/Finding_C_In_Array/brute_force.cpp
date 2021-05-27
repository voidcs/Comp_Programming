#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("out.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<vector<char>> v(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>v[i][j];
        }
    }
    cout<<n<<" "<<m<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
    int ans = 0;
    vector<array<int, 5>> point;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //Try cell (i, j) as a starting point
            //Try making top horizontal part of C of length h
            for(int h = 2; j + h <= m; h++){
                //Try making down length of d - 1
                for(int d = 3; i + d <= n; d++){
                    //Try making bottom horizontal part of c length z
                    for(int z = 2; z + j <= m; z++){
                        bool valid = 1;
                        for(int a = 0; a < h; a++)
                            valid &= (v[i][j+a] == '.');
                        for(int b = 0; b < d; b++)
                            valid &= (v[i+b][j] == '.');
                        for(int c = 0; c < z; c++)
                            valid &= (v[i+d-1][j+c] == '.');   
                        if(valid){
                            ans++;
                            point.push_back({i, j, h, d, z});
                        }
                    }
                }
            }
        }
    }
    cout<<"ans: "<<ans<<endl;
    for(auto x: point){
        cout<<"x: "<<x[0]<<"  y: "<<x[1]<<"  top hori length: "<<x[2]<<"  vertical length: "<<x[3]<<"  bottom hori length: "<<x[4]<<endl;
    }
    
    return 0;
}