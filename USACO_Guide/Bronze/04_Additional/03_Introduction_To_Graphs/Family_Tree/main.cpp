#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);
    int n;
    string a, b;
    cin>>n>>a>>b;
    map<string, set<string>> m;
    map<string, string> par;
    map<string, int> dist;
    for(int i = 0; i < n; i++){
        string x, y;
        cin>>x>>y;
        m[x].insert(y);
        par[y] = x;
        m[y];
    }
    function<void(string)> bfs = [&](string u){
        for(auto x: m){
            dist[x.first] = -1;
        }
        dist[u] = 0;
        queue<string> q;
        q.push(u);
        while(q.size()){
            u = q.front();
            q.pop();
            for(auto c: m[u]){
                if(dist[c] == -1){
                    dist[c] = dist[u] + 1;
                    q.push(c);
                }
            }
        }
    };
    //If we can find b directly from a, b is a child of a
    bfs(a);
    if(dist[b] != -1){
        if(dist[b] == 1){
            cout<<a<<" is the mother of "<<b<<endl;
        }
        else{
            cout<<a<<" is the ";
            for(int i = 0; i < dist[b]-2; i++){
                cout<<"great-";
            }
            cout<<"grand-mother of "<<b<<endl;
        }
        return 0;
    }
    //If we can find a directly from b, a is a child of b
    bfs(b);
    if(dist[a] != -1){
        if(dist[a] == 1){
            cout<<b<<" is the mother of "<<a<<endl;
        }
        else{
            cout<<b<<" is the";
            for(int i = 0; i < dist[a]-2; i++){
                cout<<"great-";
            }
            cout<<" grand-mother of "<<a<<endl;
        }
        return 0;
    }
    //If a and b are direct children of any node, then they are siblings
    for(auto x: m){
        bfs(x.first);
        if(dist[a] == dist[b] && dist[a] == 1){
            cout<<"SIBLINGS\n";
            return 0;
        }
    }
    for(auto x: m){
        bfs(x.first);
        if(dist[a] != -1 && dist[b] != -1){
            int d = dist[a] - dist[b];
            if(d < 0){
                swap(a, b);
                d = -d;
            }
            //If both a and b are findable from a bfs, we must check if they are even on the same
            //side of the tree
            //To do this, bfs from the parent of the higher node and see if you can still find both
            //If you cannot find both, they are on different sides of the tree and are cousins
            //Otherwise one is a (maybe great) aunt of another
            string p = par[b];
            bfs(p);
            if(dist[a] == -1 || dist[b] == -1){
                cout<<"COUSINS\n";
                return 0;
            }
            cout<<b<<" is the ";
            for(int i = 0; i < d-1; i++)
                cout<<"great-";
            cout<<"aunt of "<<a<<endl;
            return 0;
        }
    }
    cout<<"NOT RELATED\n";

    return 0;
}
