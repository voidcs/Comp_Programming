#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll start_x, start_y, end_x, end_y;
    cin>>start_x>>start_y>>end_x>>end_y;
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll dx = 0, dy = 0;
    for(char c: s){
        if(c == 'U')
            dy++;
        else if(c == 'D')
            dy--;
        else if(c == 'L')
            dx--;
        else if(c == 'R')
            dx++;
    }
    ll l = 0, r = 1e18;
    ll ans = -1;
    auto valid = [&](ll days){
        ll x = start_x;
        ll y = start_y;
        x += dx * (days / n);
        y += dy * (days / n);
        for(int i = 0; i < days % n; i++){
            if(s[i] == 'U')
                y++;
            else if(s[i] == 'D')
                y--;
            else if(s[i] == 'L')
                x--;
            else if(s[i] == 'R')
                x++;
        }
        return abs(x - end_x) + abs(y - end_y) <= days;
    };
    while(l <= r){
        ll m = (l + r) / 2;
        if(valid(m)){
            ans = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    cout<<ans<<"\n";
} 
