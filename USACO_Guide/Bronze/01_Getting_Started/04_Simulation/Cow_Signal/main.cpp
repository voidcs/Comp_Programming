#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int n, m, k;
    cin>>n>>m>>k;
    for(int i = 0; i < n; i++){
        string row;
        for(int j = 0; j < m; j++){
            char c;
            cin>>c;
            for(int x = 0; x < k; x++)
                row += c;
        }
        for(int j = 0; j < k; j++)
            cout<<row<<endl;
    }
    return 0;
}
