#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    string repeat;
    cout<<s;
    int start = 0;
    for(int i = 1; i < n; i++){
        //cout<<s.substr(0, i)<<"   "<<s.substr(n-i, i)<<endl;
        if(s.substr(0, i) == s.substr(n-i, i))
            start = i;
    }
    for(int i = start; i < n; i++)
        repeat += s[i];
    //cout<<"r: "<<repeat<<endl;
    for(int i = 1; i < k; i++)
        cout<<repeat;
    return 0;
}
