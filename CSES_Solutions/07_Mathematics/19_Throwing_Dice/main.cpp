#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mat vector<vector<ll>>
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    mat v(6, vector<ll>(6, 0));
    for(int i = 0; i < 5; i++)
        v[i][i+1] = 1;
    for(int i = 0; i < 6; i++)
        v[5][i] = 1;
    function<mat(mat, mat)>  mult = [&](mat a, mat b){
        mat res(6, vector<ll>(6, 0));
        
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                res[i][j] = 0;
                for(int k = 0; k < 6; k++){
                    res[i][j] += a[i][k] * b[k][j];
                    res[i][j] %= mod;
                }
            }
        }
        return res;
    };
    function<mat(ll)> expo_pow = [&](ll power){
        mat res(6, vector<ll>(6, 0));
        for(int i = 0; i < 6; i++)
            res[i][i] = 1;
        while(power){
            if(power%2){
                res = mult(res, v);
            }
            power /= 2;
            v = mult(v, v);
        }
        return res;
    };

    cout<<v[5][5]<<endl;
    return 0; 
}