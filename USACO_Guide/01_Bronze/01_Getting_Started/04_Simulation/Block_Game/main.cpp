#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int n;
    cin>>n;
    map<char, int> m;
    for(int i = 0; i < n; i++){
        string a, b;
        cin>>a>>b;
        map<char, int> x, y;
        for(char c: a)
            x[c]++;
        for(char c: b)
            y[c]++;
        for(char i = 'a'; i <= 'z'; i++){
            m[i] += max(x[i], y[i]);
        }
    }
    for(char i = 'a'; i <= 'z'; i++)
        cout<<m[i]<<endl;
    return 0;
}