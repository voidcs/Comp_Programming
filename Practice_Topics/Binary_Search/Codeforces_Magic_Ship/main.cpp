#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://codeforces.com/contest/1117/problem/C

int main(){
    ll startX, startY, endX, endY;
    cin>>startX>>startY>>endX>>endY;
    ll n;
    string str;
    cin>>n>>str;
    
    ll x = 0, y = 0;
    for(int i = 0; i < n; i++){
        char c = str[i];
        if(c == 'U')
            y++;
        if(c == 'D')
            y--;
        if(c == 'L')
            x--;
        if(c == 'R')
            x++;
    }
    
    auto possible = [&](ll days) {
        ll nx = days / n * x;
        ll ny = days / n * y;
        for (int i = 0; i < days % n; i++) {
            char c = str[i];
            if (c == 'L')
                nx--;
            if (c == 'R')
                nx++;
            if (c == 'U')
                ny++;
            if (c == 'D')
                ny--;
        }
        return abs(startX + nx - endX) + abs(startY + ny - endY) <= days;
    };
    
    ll l = 0, r = 2e14, ans = -1;
    while(l <= r){
        ll m = (l+r)/2;
        if(possible(m)){
            ans = m;
            r = m-1;
        }
        else{
            l = m+1;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}