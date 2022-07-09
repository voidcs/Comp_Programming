#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n*2);
        bool ok = 1;
        for(ll &x: v){
            cin>>x;
        }
        sort(v.begin(), v.end());

        //Check that there exists pairs of each sum in the input
        for(int i = 0; i < 2*n; i += 2){
            if(v[i] != v[i+1])
                ok = 0;
        }

        //Ans stores the 2n distinct numbers
        vector<ll> ans = {1LL};
        ll inc = 2;
        for(int i = 2; i < 2*n; i+=2){
            ll expected = v[i-1] + inc;
            if(v[i] < expected){    //If this number is less than we expect we break to avoid overflow
                ok = 0;
                break;
            }
            if( (v[i] - expected) % (inc) == 0){
                ans.push_back(1LL + ans.back() + (v[i] - expected) / inc);
            }
            else{   //If v[i] is not divisible by inc, then it cannot possibly be constructed
                ok = 0;
                break;
            }
            inc += 2;
        }

        if(!ok){
            cout<<"NO\n";
            continue;
        }


        //It's possible by that sequence does not start with 1, -1 but instead all values are incremented by a constant
        //We need to check that this is a possible constant
        //To do this, check if the difference between the sum of (sequence starting at 1) and the input lowest sum is divisible by 2*n
        for(int i = 0; i < n; i++)
            ans.push_back(-ans[i]);
        ll sum = 0;
        for(int i = 0; i < ans.size(); i++){
            sum += abs(1 - ans[i]);
            if(sum > v[0]){
                ok = 0;
                break;
            }
        }
        if( (v[0] - sum) % (2*n) )
            ok = 0;
        if(!ok)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
}
