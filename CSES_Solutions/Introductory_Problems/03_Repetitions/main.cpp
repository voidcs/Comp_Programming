#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string str;
    cin>>str;
    
    ll n = str.length();
    char curr = 'A';
    ll ans = 0, count = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == curr){
            count++;
            ans = max(count, ans);
        }
        else{
            count = 1;
            curr = str[i];
        }
    }
    cout<<ans<<endl;
    
    return 0;
}