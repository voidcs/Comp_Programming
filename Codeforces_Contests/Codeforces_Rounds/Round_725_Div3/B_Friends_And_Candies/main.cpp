#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        int sum = 0;
        for(int &x: v){
            cin>>x;
            sum += x;
        }
        if(sum % n)
            cout<<"-1\n";
        else{
            int mid = sum / n;
            int ans = 0;
            for(int i = 0; i < n; i++){
                if(v[i] > mid)
                    ans++;
            }
            cout<<ans<<endl;
        }
    }
    return 0; 
} 