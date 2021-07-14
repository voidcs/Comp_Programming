#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int cnt = 1;
        while(i+1 < n && v[i+1] > v[i]){
            cnt++;
            i++;
        }
        ans.push_back(cnt);
    }
    cout<<ans.size()<<endl;
    for(auto x: ans)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
