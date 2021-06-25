#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    string s;
    cin>>n>>s;
    map<char, int> m;
    m['0'] = 0, m['1'] = 0, m['2'] = 0;
    for(auto x: s)
        m[x]++;
    int need = n/3;
    //If we need more '0's, change them at the beginning
    for(int i = 0; i < n; i++){
        if(m['0'] >= need)
            break;
        if(s[i] != '0' && m[s[i]] > need){
            m[s[i]]--;
            s[i] = '0';
            m['0']++;
        }
    }
    //If we need more '2's, change them at the end
    for(int i = n-1; ~i; i--){
        if(m['2'] >= need)
            break;
        if(s[i] != '2' && m[s[i]] > need){
            m[s[i]]--;
            s[i] = '2';
            m['2']++;
        }
    }
    //Now we just have to add the 1's
    //If we have to replace a '0' with a '1', then we better do it from the end
    //If we have to replace a '2' with a '1', then we should do it from the front
    for(int i = 0; i < n; i++){
        if(m['2'] == need)
            break;
        if(s[i] == '2'){
            m['2']--;
            s[i] = '1';
        }
    }
    for(int i = n-1; ~i; i--){
        if(m['0'] == need)
            break;
        if(s[i] == '0'){
            m['0']--;
            s[i] = '1';
        }
    }
    cout<<s<<endl;

    return 0;
}
