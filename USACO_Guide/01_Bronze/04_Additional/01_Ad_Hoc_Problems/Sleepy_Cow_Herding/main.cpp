#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e9;

int main(){
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    vector<int> v(3);
    for(int &x: v)
        cin>>x;
    sort(v.begin(), v.end());
    if(v[2] - v[1] == 1 && v[1] - v[0] == 1)
        cout<<"0\n";
    else if(v[1] - v[0] == 2 || v[2] - v[1] == 2)
        cout<<"1\n";
    else
        cout<<"2\n";
    cout<<max({0, (v[1] - v[0] - 1), (v[2] - v[1] - 1)})<<endl;
   
    return 0;
}