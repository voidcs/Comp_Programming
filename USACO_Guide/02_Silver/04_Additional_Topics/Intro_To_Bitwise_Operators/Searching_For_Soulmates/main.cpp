#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        ll a, b;
        cin>>a>>b;
        //Find some point in A's steps to decrease it to, and then increment it to some point in B's steps
        vector<ll> a_steps, b_steps;
        while(a != 1){
            a_steps.push_back(a);
            if(a % 2)
                a += 1;
            else
                a /= 2;
        }
        a_steps.push_back(1);
        while(b != 1){
            b_steps.push_back(b);
            if(b % 2)
                b--;
            else
                b /= 2;
        }
        b_steps.push_back(1);
        ll ans = INF;
        for(int i = 0; i < a_steps.size(); i++){
            for(int j = 0; j < b_steps.size(); j++){
                if(a_steps[i] <= b_steps[j]){
                    ans = min(ans, i + j + b_steps[j] - a_steps[i]);
                }
            }
        }
        cout<<ans<<"\n";
    }
}
