#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<int> v(n), in(n);
    for(int &x: v){
        cin>>x;
        x--;
        in[x]++;
    }
    vector<int> vis(n), ans(n, -1), in_cycle(n, -1);
    auto bfs = [&](int source){
        stack<int> s;
        queue<int> q;
        int first_cycle = -1;
        q.push(source);
        while(q.size()){
            int u = q.front();
            q.pop();
            s.push(u);
            vis[u] = 1;
            if(!vis[v[u]])
                q.push(v[u]);
            else if(vis[v[u]]){
                if(ans[v[u]] != -1){    //If the answer of this node is set, assign its answer to all nodes in stack
                    first_cycle = ans[v[u]];
                    while(s.size()){
                        int u = s.top();
                        s.pop();
                        ans[u] = first_cycle;
                        in_cycle[u] = 0;
                    }
                    return;
                }
                else
                    first_cycle = v[u];
            }
        }
        //If we make it here, then we have made it to an unvisited cycle
        while(s.top() != first_cycle){
            int u = s.top();
            s.pop();
            ans[u] = u;
            in_cycle[u] = 1;
        }
        ans[first_cycle] = first_cycle;
        s.pop();
        while(s.size()){
            int u = s.top();
            s.pop();
            in_cycle[u] = 0;
            ans[u] = first_cycle;
        }
    };
    for(int i = 0; i < n; i++){
        if(in[i] == 0){
            bfs(i);
        }
    }
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            ans[i] = i;
        }
    }
    for(int i = 0; i < n; i++)
        cout<<ans[i] + 1<<" ";
    cout<<"\n";
}
