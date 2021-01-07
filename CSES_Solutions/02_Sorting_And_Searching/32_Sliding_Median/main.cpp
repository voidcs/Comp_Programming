#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ar array
const ll INF = 1e18;

int main(){
    ll n, k;
    cin>>n>>k;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    
    if(k == 1){
        for(int i = 0; i < n; i++)
            cout<<a[i]<<" ";
        return 0;
    }
    
    ar<ll, 2> med = {-1};
    set<ar<ll, 2>> bot, top;
    
    auto fix = [&](){
        int m = 1 + bot.size() + top.size();
        if(bot.size() < (m-1)/2){
            bot.insert(med);
            med = *top.begin();
            top.erase(med);
        }
        if(bot.size() > (m-1)/2){
            top.insert(med);
            med = *--bot.end();
            bot.erase(med);
        }
    };
    
    auto add = [&](ar<ll, 2> x){
        if(med[0] == -1){
            med = x;
            return;
        }
        if(x < med)
            bot.insert(x);
        else
            top.insert(x);
        fix();
    };
    
    auto rem = [&](ar<ll, 2> x){
        if(x == med){
            med = *top.begin();
            top.erase(med);
        }
        else if(x < med)
            bot.erase(x);
        else
            top.erase(x);
        fix();
    };
    
    for(int i = 0; i < k-1; i++)
        add({a[i], i});
        
    for(int i = k-1; i < n; i++){
        add({a[i], i});
        cout<<med[0]<<" ";
        rem({a[i-k+1], i-k+1});
    }
    
    return 0;
}