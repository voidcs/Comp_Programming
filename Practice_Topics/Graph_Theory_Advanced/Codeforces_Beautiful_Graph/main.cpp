#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 998244353
        
//PROBLEM LINK
//https://codeforces.com/contest/1093/problem/D

vector<ll> adj[1000005];
bool vis[1000005];
int col[1000005];
int par[1000005];
ll cnt;

bool dfs(int node, int c, int p){
    cnt++;
    par[node] = p;
    vis[node] = 1;
    col[node] = c;
    
    for(int child: adj[node]){
        if(vis[child] == 0){
            bool res = dfs(child, c^1, p);
            if(!res)
                return false;
        }
        else{
            if(col[node] == col[child]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, E;
        cin>>n>>E;
        
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            vis[i] = 0;
            col[i] = 0;
            par[i] = 0;
        }
        
        for(int i = 0; i < E; i++){
            ll a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        bool valid = 1;
        ll ans = 1;
        
        for(int i = 1; i <= n; i++){
            cnt = 0;
            if(!vis[i]){
                valid = dfs(i, 0, i);
                if(!valid)
                    break;
                ll x = (cnt-1) / 2;
                //cout<<"X: "<<x<<endl;

                if(cnt%2){
                    ll add = 1;
                    for(int j = 0; j < x; j++){
                        add = (add * 2) % mod;
                    }
                    
                    ans = (3 * ((ans * add) % mod)) % mod;
                }
                else{
                    ll add = 1;
                    for(int j = 0; j < x; j++){
                        add = (add * 2) % mod;
                    }
                    ans = (4 * ((ans * add) % mod)) % mod;
                    //cout<<"JUNK: "<<(4 * ((ans * add) % mod)) % mod<<endl;
                }
                //cout<<"COUNT: "<<cnt<<endl;
            }
            
        }  
        if(!valid){
            cout<<"0\n";
            continue;
        }
//        for(int i = 1; i <= n; i++){
//            cout<<"node: "<<i<<"   "<<par[i]<<endl;
//        }
        cout<<ans<<endl;
        
    }
    return 0;
}