#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    bool ok = 0;
    vector<array<int, 2>> parity;
    for(int i = 0; i < n; i++){
        int j = i;
        while(j < n && v[j]%2 == v[i]%2){
            j++;
        }
        parity.push_back({j-i, v[i]%2});
        i = j-1;
    }
//    for(auto x: parity){
//        cout<<x[0]<<" "<<x[1]<<endl;
//    }
    stack<array<int, 2>> s;
    for(auto x: parity){
        if(x[0] % 2 == 0)
            continue;
        if(s.empty())
            s.push(x);
        else{
            if(s.top()[1] == x[1]){
                //cout<<"matched\n";
                s.pop();
            }
            else
                s.push(x);
        }
    }
    if(s.size() <= 1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}