#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=7CTpoVNIc8o&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=29

vector<int> adj[100001];
vector<int> ans;
int in[1000001];
 
void kahn(int n){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(in[i] == 0)
            q.push(i);
    }
    
    while(!q.empty()){
        int curr = q.front();
        ans.push_back(curr);
        q.pop();
        
        for(int node: adj[curr]){
            in[node]--;
            if(in[node] == 0)
                q.push(node);
        }
    }
    
    cout<<"Topological Sort: ";
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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
    
    kahn(n);
    
    return 0;
}