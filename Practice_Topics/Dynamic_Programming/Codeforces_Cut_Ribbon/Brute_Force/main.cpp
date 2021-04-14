#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/contest/189/problem/A

int main(){
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    int ans = 0;
    for(int i = 0; i <= n/a; i++){
        for(int j = 0; j <= n/b; j++){
            int sum = (a*i) + (b*j);
            int x = (n - sum) / c;
            if(sum <= n && (n-sum) % c == 0){
                ans = max(ans, i + j + x);
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}