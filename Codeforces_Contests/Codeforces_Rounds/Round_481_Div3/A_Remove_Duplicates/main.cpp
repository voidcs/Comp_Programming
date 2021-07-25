#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    set<int> s;
    vector<int> ans;
    for(int i = n-1; i >= 0; i--){
        if(!s.count(v[i])){
            s.insert(v[i]);
            ans.push_back(v[i]);
        }
    }
    cout<<ans.size()<<endl;
    reverse(ans.begin(), ans.end());
    for(auto x: ans)
        cout<<x<<" ";
    return 0;
}
