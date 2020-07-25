#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://codeforces.com/contest/5/problem/C

ll start[1000001];
ll extend[1000001];
ll freq[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>str;
    ll n = str.length();
    ll ans = 0;
    stack<ll> s;
    for(int i = 0; i < n; i++){
        char c = str[i];
        if(c == '('){
            s.push(i);
        }
        else{
            if(s.empty()){
                start[i] = extend[i] = -1;
            }
            else{
                ll index = s.top();
                s.pop();
                
                start[i] = extend[i] = index;
                if(index > 0 && str[index-1] == ')' && start[index-1] >= 0)
                    extend[i] = extend[index-1];
                
                ll len = i - extend[i] + 1;
                freq[len]++;
                ans = max((ll)ans, (ll)len);
            }
        }
    }
    freq[0] = 1;
    cout<<ans<<" "<<freq[ans];
    return 0;
}