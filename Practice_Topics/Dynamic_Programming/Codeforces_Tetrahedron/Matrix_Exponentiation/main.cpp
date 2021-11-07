#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
#define mat vector<vector<ll>>

int main(){
    int n;
    cin>>n;
    vector<vector<ll>> v(4, vector<ll>(4, 1));
    for(int i = 0; i < 4; i++)
        v[i][i] = 0;
    function<mat(mat, mat)> mult = [&](mat a, mat b){
        mat res(4, vector<ll>(4, 0));
        for(int i = 0; i < 4; i++){
            for(int k = 0; k < 4; k++){
                for(int j = 0; j < 4; j++){
                    res[i][j] += (a[i][k] * b[k][j]);
                    res[i][j] %= mod;
                }
            }
        }
        return res;
    };
    
    function<void(ll)> expo_power = [&](ll power){
        mat res(4, vector<ll>(4, 0));
        for(int i = 0; i < 4; i++)
            res[i][i] = 1;
        while(power){
            if(power%2)
                res = mult(v, res);
            v = mult(v, v);
            power /= 2;
        }
        v = res;
    };
    expo_power(n);
    cout<<v[0][0]<<endl;
    return 0;
}