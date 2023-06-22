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
    vector<int> ans;
    for(int x: v){
        int i = upper_bound(ans.begin(), ans.end(), x) - ans.begin();
        if(i == ans.size())
            ans.push_back(x);
        else
            ans[i] = x;
    }
    cout<<ans.size()<<"\n";
}
