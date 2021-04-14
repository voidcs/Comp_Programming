#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/144/A

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    int tallest, shortest;
    int best = -1;
    for(int i = 0; i < n; i++){
        if(v[i] > best){
            tallest = i;
            best = v[i];
        }
    }
    best = 1e5;
    for(int i = 0; i < n; i++){
        if(v[i] <= best){
            shortest = i;
            best = v[i];
        }
    }
    int ans = tallest + (n-1-shortest) - (tallest > shortest);
    cout<<ans<<endl;
    
    return 0;
}