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
    sort(v.begin(), v.end());
    int x = v[n-2] - v[0];
    int y = v[n-1] - v[1];
    cout<<min(x, y)<<endl;
    return 0;
}
