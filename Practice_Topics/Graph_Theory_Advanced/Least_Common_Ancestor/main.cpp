#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=ZPa1Dwr9vAg&list=PL2q4fbVm1Ik64I3VqbVGRfl_OgYzvzt9m&index=6

vector<int> adj[1001];
const int maxN = 10;    //Max power of 2 that can go into N (1000)
int level[1001], LCA[1001][maxN+1];

void dfs(int node, int lvl, int par){
    level[node] = lvl;
    LCA[node][0] = par;
    
    for(int child: adj[node]){
        if(child != par){
            dfs(child, lvl+1, node);
        }
    }
}

void init(int n){
    dfs(1, 0, -1);
    for(int i = 1; i <= maxN; i++){
        for(int j = 1; j <= n; j++){
            if(LCA[j][i-1] != -1){
                int par = LCA[j][i-1];
                LCA[j][i] = LCA[par][i-1];
            }
        }
    }
}

int getLCA(int a, int b){
    if(level[b] < level[a])
        swap(a, b);
    int d = level[b] - level[a];
    while(d){
        int i = log2(d);
        b = LCA[b][i];
        d -= 1 << i;
    }
    
    if(a == b)
        return a;
    
    for(int i = maxN; i >= 0; i--){
        if(LCA[a][i] != -1 && LCA[a][i] != LCA[b][i]){
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    
    return LCA[a][0];
}

int getDist(int a, int b){
    int lca = getLCA(a, b);
    return level[a] + level[b] - 2*level[lca];
}

int main(){
    int n;
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= maxN; j++){
            LCA[i][j] = -1;
        }
    }
    
    for(int i = 1; i < n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    init(n);
    
    int q;
    cin>>q;
    
    while(q--){
        int a, b;
        cin>>a>>b;
        cout<<getDist(a, b)<<endl;
    }
    
    return 0;
}