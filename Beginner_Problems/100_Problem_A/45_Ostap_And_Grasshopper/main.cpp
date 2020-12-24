#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    int n, k;
    cin>>n>>k;
    string str;
    cin>>str;
    bool ans = 1;
    int st;
    for(int i = 0; i < n; i++){
        if(str[i] == 'G')
            st = i;
    }
    for(int i = st+k; i < n; i+=k){
        if(str[i] == '#')
            break;
        ans &= (str[i] != 'T');
    }
    for(int i = st-k; i >= 0; i-=k){
        if(str[i] == '#')
            break;
        ans &= (str[i] != 'T');
    }
    if(ans)
        cout<<"NO\n";
    else
        cout<<"YES\n";
    
    return 0;
}