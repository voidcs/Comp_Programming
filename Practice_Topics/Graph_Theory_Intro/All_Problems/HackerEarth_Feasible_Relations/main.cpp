#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//PROBLEM LINK
//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/description/
//Reference video
//https://www.youtube.com/watch?v=iygT1oD7C_s&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=20
vector<int> adj[1000001];
bool vis[1000001];
int component[1000001];
int cc;

void dfs(int node){
    vis[node] = 1;
    component[node] = cc;
    
    for(int child: adj[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        cc = 0;
        int n, k;
        cin>>n>>k;
        vector<pair<int, int>> v;
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            vis[i] = 0;
        }
        
        int a, b;
        while(k--){
            string str;
            cin>>a>>str>>b;
            if(str == "!=")
                v.push_back({a,b});
            else{
                adj[a].push_back(b);
                adj[b].push_back(a);
            }    
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i);
                cc++;
            }
        }
        
        bool flag = 1;
        for(int i = 0; i < v.size(); i++){
            a = v[i].first;
            b = v[i].second;
            if(component[a] == component[b]){
                flag = 0;
            }
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}