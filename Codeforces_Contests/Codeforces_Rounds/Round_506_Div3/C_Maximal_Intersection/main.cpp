#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<array<int, 2>> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i][0]>>v[i][1];
    if(n == 2){
        cout<<max(v[0][1] - v[0][0], v[1][1] - v[1][0])<<endl;
        return 0;
    }
    multiset<int> right;
    multiset<int, greater<int>> left;
    for(int i = 0; i < n; i++){
        left.insert(v[i][0]);
        right.insert(v[i][1]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        left.erase(left.lower_bound(v[i][0]));
        right.erase(right.lower_bound(v[i][1]));
        int intersection = max(0, *right.begin() - *left.begin());
        //cout<<"i: "<<i<<"  "<<intersection<<endl;
        ans = max(ans, intersection);
        left.insert(v[i][0]);
        right.insert(v[i][1]);
    }
    cout<<ans<<endl;
    return 0;
}
