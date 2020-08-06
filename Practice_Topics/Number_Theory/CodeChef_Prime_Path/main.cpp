#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
//PROBLEM LINK
//https://www.spoj.com/problems/PPATH/
//REFERENCE VIDEO
//https://www.youtube.com/watch?v=eYf4NFc2s1w&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=19

int dist[100001], vis[100001];
vector<int> primes;
vector<int> adj[100001];

bool isPrime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

void inil(){
    for(int i = 1000; i <= 9999; i++){
        if(isPrime(i))
            primes.push_back(i);
    }
    
    for(int i = 0; i < primes.size(); i++){
        for(int j = i+1; j < primes.size(); j++){
            int count = 0;
            int a = primes[i];
            int b = primes[j];
            
            while(a){
                if(a%10 == b%10){
                    count++;
                }
                a /= 10, b /= 10;
            }
            if(count == 3){
                //cout<<"Added: "<<primes[i]<<" and "<<primes[j]<<endl;
                adj[primes[i]].push_back(primes[j]);
                adj[primes[j]].push_back(primes[i]);
            }
        }
    }
}

void bfs(int curr){
    dist[curr] = 0;
    vis[curr] = 1;
    queue<int> q;
    q.push(curr);
    
    while(!q.empty()){
        curr = q.front();
        q.pop();

        for(int child: adj[curr]){
            if(!vis[child]){
                vis[child] = 1;
                //cout<<"DIST OF "<<child<<" is "<<dist[curr] + 1<<endl;
                dist[child] = dist[curr] + 1;
                q.push(child);
            }
        }
        
    }
}

int main(){
    inil();
    ll t;
    cin>>t;
    while(t--){
        ll a, b;
        cin>>a>>b;
        
        for(int i = 0; i < 100001; i++){
            vis[i] = 0;
            dist[i] = -1;
        }
        
        bfs(a);
        if(dist[b] == -1){
            cout<<"Impossible\n";
        }
        else
            cout<<dist[b]<<endl;
    }
    return 0;
}

//1033 8179