#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/43/A

int main(){
    int n;
    cin>>n;
    map<string, int> m;
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        m[s]++;
    }
    int ans = 0;
    string name;
    for(auto x: m){
        if(x.second > ans){
            ans = x.second;
            name = x.first;
        }
    }
    cout<<name<<endl;
    return 0;
}