#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n;
    cin>>n;
    n *= 2;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    int ans = 1e9;
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            vector<int> t;
            for(int k = 0; k < n; k++){
                if(k != i && k != j){
                    t.push_back(v[k]);
                }
            }
            int sum = 0;
            for(int k = 1; k < t.size(); k+=2){
                sum += (t[k] - t[k-1]);
            }
            ans = min(ans, sum);
        }
    }
    cout<<ans<<endl;
    return 0;
}