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
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x = v[i];
        while(v[i] == x){
            i++;
        }
        ans++, i--;
    }
    cout<<ans<<endl;
    
    return 0;
}