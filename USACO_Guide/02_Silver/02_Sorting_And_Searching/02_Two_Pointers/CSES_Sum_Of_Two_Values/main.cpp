#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, x;
    cin>>n>>x;
    vector<array<int, 2>> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i][0];
        v[i][1] = i+1;
    }
    sort(v.begin(), v.end());
    int l = 0, r = n-1;
    while(l < r){
        int sum = v[l][0] + v[r][0];
        if(sum == x){
            cout<<v[l][1]<<" "<<v[r][1]<<endl;
            return 0;
        }
        else if(sum > x){
            r--;
        }
        else{
            l++;
        }
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}
