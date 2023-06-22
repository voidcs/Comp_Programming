#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    string s;
    cin>>s;
    vector<string> ans;
    sort(s.begin(), s.end());
    do{
        ans.push_back(s);
    }while(next_permutation(s.begin(), s.end()));

    cout<<ans.size()<<endl;
    for(auto x: ans)
        cout<<x<<endl;
    cout<<endl;
            
    return 0;
}