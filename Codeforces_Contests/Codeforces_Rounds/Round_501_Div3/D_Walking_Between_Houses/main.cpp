#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, k, dist;
    cin>>n>>k>>dist;
    ll fastest = (dist+n-2) / (n-1);
    if(fastest > k || k > dist)
        cout<<"NO\n";
    else{
        auto valid = [&](ll mid){
            ll x = mid * (n-1);
            ll distLeft = dist-x;
            ll stepsLeft = k - mid;
            return distLeft >= stepsLeft;
        };
        ll l = 0, r = (dist+n-2) / (n-1);
        ll whole = 0;
        while(l <= r){
            ll mid = (l+r) / 2;
            if(valid(mid)){
                whole = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        vector<ll> ans;
        for(int i = 0; i < whole; i++){
            if(i%2 == 0)
                ans.push_back(n);
            else
                ans.push_back(1);
        }
        r = k - whole;
        if(ans.size()){
            if(r){
                //cout<<"?\n";
                ll rem = dist - (whole * (n-1)) - (r-1);
                if(ans.back() + rem <= n)
                    ans.push_back(ans.back() + rem);
                else
                    ans.push_back(ans.back() - rem);
            }
            bool inc = (ans.back() == 1);
            for(int i = 0; i < r-1; i++){
                if(ans.back() == n)
                    inc = 0;
                else if(ans.back() == 1)
                    inc = 1;
                if(inc)
                    ans.push_back(ans.back()+1);
                else
                    ans.push_back(ans.back()-1);
            }
        }
        else{
            if(k == 1)
                ans.push_back(dist+1);
            else{
                ll rem = dist - (k-1);
                ans.push_back(rem+1);
                bool inc = (ans.back() != n);
                for(int i = 0; i < k-1; i++){
                    if(ans.back() == n)
                        inc = 0;
                    else if(ans.back() == 1)
                        inc = 1;
                    if(inc)
                        ans.push_back(ans.back()+1);
                    else
                        ans.push_back(ans.back()-1);
                }
            }
        }
        cout<<"YES\n";
        for(auto x: ans)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
