#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        vector<int> mark(n);
        mark[i] = 1;
        for(int j = i; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(v[k] - v[j] <= mark[j] && mark[k] == 0){
                    mark[k] = mark[j] + 1;
                }
            }
        }
        for(int j = i; j >= 0; j--){
            for(int k = j-1; k >= 0; k--){
                if(v[j] - v[k] <= mark[j] && mark[k] == 0){
                    mark[k] = mark[j] + 1;
                }
            }
        }
        int l = -1, r = -1;
        for(int j = 0; j < n; j++){
            if(l == -1 && mark[j] > 0)
                l = j;
            if(mark[j] > 0)
                r = j;
        }
        ans = max(ans, r - l + 1);
    }
    cout<<ans<<endl;
    
    return 0;
}