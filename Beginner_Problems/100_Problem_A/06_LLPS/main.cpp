#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    char ans = 'a';
    string str;
    cin>>str;
    map<char, int> m;
    for(int i = 0; i < str.length(); i++){
        ans = max(ans, str[i]);
        m[str[i]]++;
    }
    for(int i = 0; i < m[ans]; i++)
        cout<<ans;
    return 0;
}