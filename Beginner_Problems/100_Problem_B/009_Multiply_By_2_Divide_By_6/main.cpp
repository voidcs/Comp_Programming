#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/problemset/problem/1374/B

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll three = 0, two = 0;
        while(n%2 == 0 || n%3 == 0){
            if(n%2 == 0){
                two++;
                n /= 2;
            }
            if(n%3 == 0){
                three++;
                n /= 3;
            }
        }
        if(n != 1 || two > three)
            cout<<"-1\n";
        else{
            ll ans = 0;
            ans += three-two;
            ans += three;
            cout<<ans<<endl;
        } 
    }
    return 0;
}