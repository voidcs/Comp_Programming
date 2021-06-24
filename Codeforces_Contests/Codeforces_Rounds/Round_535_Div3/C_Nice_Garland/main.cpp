#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    string s;
    cin>>n>>s;
    string x = "BGR", ans;
    int cnt = 1e9;
    do{
        int diff = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != x[i%3])
                diff++;
        }
        if(diff < cnt){
            cnt = diff;
            ans = x;
        }
    }while(next_permutation(x.begin(), x.end()));
    cout<<cnt<<endl;
    for(int i = 0; i < n; i++)
        cout<<ans[i%3];
    return 0;
}
