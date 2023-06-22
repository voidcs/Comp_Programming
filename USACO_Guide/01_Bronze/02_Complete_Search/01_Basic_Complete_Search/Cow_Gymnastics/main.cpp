#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int k, n;
    cin>>k>>n;
    vector<vector<int>> v(k, vector<int>(n));
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            cin>>v[i][j];
        }
        //Convert the input to instead be
        //cow v[i][j] got jth place so we can compare two cows by column
        vector<int> temp(n);
        for(int j = 0; j < n; j++){
            temp[v[i][j]-1] = j;
        }
        v[i] = temp;
    }
    
    int ans = 0;
    for(int a = 0; a < n; a++){
        for(int b = a+1; b < n; b++){
            int score = 0;
            for(int i = 0; i < k; i++){
                if(v[i][a] > v[i][b])
                    score++;
                else if(v[i][a] < v[i][b])
                    score--;
                if(abs(score) == k)
                    ans++;
            }
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}