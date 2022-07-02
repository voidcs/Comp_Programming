#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int n;
    cin>>n;
    vector<array<int, 2>> v(n), ends(n);
    for(int i = 0; i < n; i++){
        cin>>v[i][0]>>v[i][1];
        ends[i][0] = v[i][0] - v[i][1];
        ends[i][1] = v[i][0] + v[i][1];
    }

    auto comp = [&](array<int, 2> a, array<int, 2> b){
        if(a[0] != b[0])
            return a[0] < b[0];
        return a[1] > b[1];
    };
    int ans = 0, end = -1;
    sort(ends.begin(), ends.end(), comp);
    for(int i = 0; i < n; i++){
        if(ends[i][1] <= end){
            ans++;
        }
        end = max(end, ends[i][1]);
    }
    cout<<n - ans<<"\n";
    return 0;
}
