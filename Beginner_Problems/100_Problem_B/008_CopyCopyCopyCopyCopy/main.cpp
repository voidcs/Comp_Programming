#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/problemset/problem/1325/B

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<int> s;
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            s.insert(x);
        }
        cout<<s.size()<<endl;
        
    }
    return 0;
}