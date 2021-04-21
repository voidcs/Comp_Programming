#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/330/A

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int &x: a)
            cin>>x;
        map<int, int> m;
        for(int x: a)
            m[x]++;
        int val;
        for(auto x: m){
            if(x.second == 1)
                val = x.first;
        }
        for(int i = 0; i < n; i++){
            if(a[i] == val)
                cout<<i+1<<endl;
        }
    }
    return 0;
}