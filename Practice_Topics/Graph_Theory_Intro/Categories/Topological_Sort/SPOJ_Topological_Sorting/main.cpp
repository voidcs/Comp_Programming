#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

//PROBLEM LINK
//https://www.spoj.com/problems/TOPOSORT/
//REFERENCE VIDEO
//https://www.youtube.com/watch?v=bS62tit40m8&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=30

vector<int> adj[100001];
vector<int> ans;
int in[1000001];
 
bool kahn(int n){
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 1; i <= n; i++){
        if(in[i] == 0)
            q.push(i);
    }
    
    while(!q.empty()){
        int curr = q.top();
        ans.push_back(curr);
        q.pop();
        
        for(int node: adj[curr]){
            in[node]--;
            if(in[node] == 0)
                q.push(node);
        }
    }
    
    return ans.size() == n;
}

int main(){
    int n, m;
    cin>>n>>m;
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        in[b]++;
    }
    
    bool flag = kahn(n);
    if(flag){
        for(auto x: ans){
            cout<<x<<" ";
        }
    }
    else{
        cout<<"Sandro fails.\n";
    }
    
    return 0;
}