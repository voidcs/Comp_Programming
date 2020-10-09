#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    string str;
    cin>>str;
    vector<ll> v(26, 0);
    ll n = str.length();
    
    for(int i = 0; i < n; i++){
        v[str[i]-'A']++;
    }
    
    int count = 0;
    char odd = 'a';
    for(int i = 0; i < 26; i++){
        if(v[i] % 2){
            count++;
            odd = static_cast<char>('A' + i);
        }
    }
    
    if(count > 1){
        cout<<"NO SOLUTION\n";
        return 0;
    }
    
    string ans;
    
    for(int i = 0; i < 26; i++){
        if(v[i]%2)
            continue;
        for(int j = 0; j < v[i]/2; j++){
            ans += static_cast<char>('A' + i);
        }
    }
    
    cout<<ans;
    for(int i = 0; i < 26; i++){
        if(v[i]%2){
            for(int j = 0; j < v[i]; j++){
                cout<<(char)('A' + i);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
   
    return 0;
}