#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(auto &x: v)
        cin>>x;
    map<ll, ll> last, first;
    vector<ll> prefix(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
        prefix[i] = sum;
        last[v[i]] = i;
        if(!first.count(v[i]))
            first[v[i]] = i;
    }

    bool valid = 0;
    for(int i = 0; i < n; i++){
        ll left = prefix[i], right = sum - prefix[i];
        //cout<<"i: "<<i<<"  l: "<<left<<"  r: "<<right<<endl;
        if(left == right){
            valid = 1;
            break;
        }
        if(abs(left-right) % 2)
            continue;
        left -= v[i], right += v[i];
        ll d = right - left;
        d /= 2;
        //cout<<"l: "<<left<<"  r: "<<right<<"  d: "<<d<<endl;
        if(last.count(d) && last[d] > i){
            //cout<<"found for i = "<<i<<"  d: "<<d<<endl;
            valid = 1;
        }
        left += v[i], right -= v[i];
        d = (left - right)/2;
        if(first.count(d) && first[d] < i){
            //cout<<"found for i = "<<i<<"  d: "<<d<<endl;
            valid = 1;
        }
    }
    if(valid)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}