#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    string s;
    cin>>n>>s;
    vector<vector<int>> dp(n+1, vector<int>(3, 1e9));
    vector<vector<pair<char, int>>> save(n+1, vector<pair<char, int>>(3));
    string x = "RGB";
    for(int i = 0; i < n; i++){
        if(i == 0){
            for(int j = 0; j < 3; j++){
                if(s[i] == x[j]){
                    dp[i][j] = 0;
                    save[i][j].first = x[j];
                }
                else{
                    dp[i][j] = 1;
                    save[i][j].first = x[j];
                }
            }
        }
        else{
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    if(j == k){
                        continue;
                    }
                    if(s[i] == x[j]){
                        if(dp[i][j] > dp[i-1][k]){
                            dp[i][j] = dp[i-1][k];
                            save[i][j].second = k;
                            save[i][j].first = x[j];
                        }
                    }
                    else{
                        if(dp[i][j] > dp[i-1][k]+1){
                            dp[i][j] = dp[i-1][k]+1;
                            save[i][j].first = x[j];
                            save[i][j].second = k;
                        }
                    }
                }
            }
        }
    }
    int ans = 1e9;
    int start = 0;
    string str;
    for(int i = 0; i < 3; i++){
        if(dp[n-1][i] < ans){
            ans = dp[n-1][i];
            start = i;
        }
    }
    n--;
    while(n >= 0){
        str += save[n][start].first;
        start = save[n][start].second;
        n--;
    }
    reverse(str.begin(), str.end());
    cout<<ans<<endl;
    cout<<str<<endl;
    return 0;
}