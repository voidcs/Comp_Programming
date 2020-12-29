#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//PROBLEM LINK
//https://codeforces.com/problemset/problem/1433/D

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1];
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        vector<int> par(n+1);
        iota(par.begin(), par.end(), 0);

        function<int(int)> find = [&](int x){
            return (x == par[x]) ? x : par[x] = find(par[x]);
        };
        function<void(int, int)> unite = [&](int x, int y){
            x = find(x), y = find(y);
            if(x != y){
                par[x] = y;
            }
        };
        
        vector<array<int, 2>> ans;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(a[i] != a[j]){
                    if(find(i) != find(j)){
                        ans.push_back({i, j});
                        unite(i, j);
                    }
                }
            }
        }
        
        if(ans.size()){
            cout<<"YES\n";
            for(auto x: ans)
                cout<<x[0]<<" "<<x[1]<<endl;
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}