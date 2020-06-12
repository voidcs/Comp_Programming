#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

typedef long long ll;
using namespace std; 
  
// A utility function to add an edge in an 
// undirected graph. 
void addEdge(unordered_map<string, int> m, vector<pair<string, int>> adj[], string u, string v, int weight) { 
    adj[m[u]].push_back(make_pair(v, weight)); 
    
    //Uncomment this to make the graph undirected
    //adj[m[v]].push_back(make_pair(u, weight)); 
} 
  
void printGraph(vector<string> index, vector<pair<string,int>> adj[], int n){ 
    string v;
    int w;
    for (int u = 0; u < n; u++) { 
        cout << "Node " << index[u] << " makes an edge with \n"; 
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++) { 
            v = it->first; 
            w = it->second; 
            cout << "\tNode " << v << " with edge weight = "
                 << w << "\n"; 
        } 
        cout << "\n"; 
    } 
} 
  
//int shortestPath(int u, int destination, bool visited[], vector<pair<string,int>> adj[], int n){
//    visited[u] = 1;
//    ll inf = 10e10;
//    ll ans = inf;
//    
//    for(int i = 0; i < n; i++){
//        if()
//    }
//}

int main() { 
    int n = 6;
    
    vector<pair<string, int>> adj[n];
    string start, end;
    int weight;
    
    unordered_map<string, int> m;
    vector<string> index {"SFO", "ORD", "JFK", "DFW", "MIA", "LAX"};
    
    for(int i = 0; i < n; i++){
        m[index[i]] = i;
    }
    
//    for(auto x: m)
//        cout<<x.first<<"     "<<x.second<<endl;
    
    freopen("input.txt", "r", stdin);
    for(int i = 0; i < 13; i++){
        cin>>start>>weight>>end;
        //cout<<"START: "<<start<<"    end: "<<end<<"     weight: "<<weight<<endl;
        addEdge(m, adj, start, end, weight);
    }
  
    printGraph(index, adj, n); 
    
    bool visited[n] = {0};
    
    
  
    return 0; 
} 