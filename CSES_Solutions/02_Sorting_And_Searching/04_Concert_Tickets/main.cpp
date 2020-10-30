#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin>>n>>m;
    multiset<int> s;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    for(int i = 0; i < m; i++){
        int t;
        cin>>t;
        auto x = s.upper_bound(t);
        if(x == s.begin())
            cout<<"-1\n";
        else{
            x--;
            cout<<*x<<endl;
            s.erase(x);
        }
    }
    return 0;
}