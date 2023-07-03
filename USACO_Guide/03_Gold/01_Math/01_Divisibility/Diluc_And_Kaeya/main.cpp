#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        map<array<int, 2>, int> m;
        array<int, 2> cnt = {0, 0};
        for(char c: s){
            if(c == 'D')
                cnt[0]++;
            else
                cnt[1]++;
            int g = __gcd(cnt[0], cnt[1]);
            array<int, 2> copy = cnt;
            copy[0] /= g;
            copy[1] /= g;
            m[copy]++;
            cout<<m[copy]<<" ";
        }
        cout<<"\n";
    }
}
