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
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += v[k];
            }
            if(sum % (j-i+1) == 0){
                int average = sum / (j-i+1);
                for(int k = i; k <= j; k++){
                    if(v[k] == average){
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}