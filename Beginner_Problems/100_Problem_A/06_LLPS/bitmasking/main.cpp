#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    string ans;
    string str;
    cin>>str;
    int n = str.length();
    for(int i = 0; i < (1<<n); i++){
        string s;
        for(int j = 0; j < n; j++){
            if(i & 1 << j)
                s += str[j];
        }
        string t = s;
        reverse(t.begin(), t.end());
        if(s == t)
            ans = max(ans, s);
    }
    cout<<ans<<endl;
    
    return 0;
}