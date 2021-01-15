#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mat vector<vector<ll>>
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    mat v = {{0, 1}, {1, 1}};
    function<mat(mat, mat)>  mult = [&](mat a, mat b){
        mat res(2, vector<ll>(2, 0));
        
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                res[i][j] = 0;
                for(int k = 0; k < 2; k++){
                    res[i][j] += a[i][k] * b[k][j];
                    res[i][j] %= mod;
                }
            }
        }
        return res;
    };
    function<mat(ll)> expo_pow = [&](ll power){
        mat res(2, vector<ll>(2, 0));
        for(int i = 0; i < 2; i++)
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
    v = expo_pow(n);
    //First two numbers of fib sequence: a = 0, b = 1
    //a_final = a*v[0][0] + b*v[1][0]
    //b_final = a*v[0][1] + b*v[1][1]
    //Since a is 0 and b is 1, we only actually have to print v[1][0]
    cout<<v[1][0]<<endl;
    return 0; 
}