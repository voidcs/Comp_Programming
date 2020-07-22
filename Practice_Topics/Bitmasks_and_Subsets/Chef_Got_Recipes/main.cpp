#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://www.codechef.com/problems/JAIN
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[32];
        for(int i = 0; i < 32; i++)
            a[i] = 0;
        
        while(n--){
            string str;
            cin>>str;
            int mask = 0;
            for(char c: str){
                if(c == 'a') mask |= (1<<0);
                if(c == 'e') mask |= (1<<1);
                if(c == 'i') mask |= (1<<2);
                if(c == 'o') mask |= (1<<3);
                if(c == 'u') mask |= (1<<4);
            }
            a[mask]++;
        }
        ll ans = 0;
        for(int i = 1; i < 32; i++){
            for(int j = i+1; j < 32; j++){
                if( (i | j) == 31)
                    ans += a[i] * a[j];
            }
        }
        ans += (a[31] * (a[31] - 1))/2;
        cout<<ans<<endl;
    }
    return 0;
}
