#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    string s;
    cin>>s;
    int n = s.length();
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]){
            char c = (i+1 < n) ? s[i+1] : '$';
            while(s[i] == s[i-1] || s[i] == c){
                s[i]++;
                if(s[i] > 'z')
                    s[i] = 'a';
            }
        }
    }
    cout<<s<<endl;
    return 0;
}
