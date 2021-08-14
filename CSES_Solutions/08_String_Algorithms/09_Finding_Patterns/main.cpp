//https://cses.fi/problemset/task/2102
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    s += "$";
    int n = s.length();
    vector<int> sa(n), c(n);
    vector<pair<pair<int, int>, int>> v(n);

    for(int i = 0; i < n; i++)
        v[i] = {{s[i] - '0', 0}, i};
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
        sa[i] = v[i].second;
    c[sa[0]] = 0;
    for(int i = 1; i < n; i++){
        c[sa[i]] = c[sa[i-1]] + !(v[i].first == v[i-1].first);
    }
    int k = 0;
    while(n > (1LL<<k)){
        for(int i = 0; i < n; i++){
            v[i] = {{c[i], c[(i + (1LL<<k)) % n]}, i};
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++)
            sa[i] = v[i].second;
        c[sa[0]] = 0;
        for(int i = 1; i < n; i++){
            c[sa[i]] = c[sa[i-1]] + !(v[i].first == v[i-1].first);
        }
        k++;
    }
    int q;
    cin>>q;
    while(q--){
        string t;
        cin>>t;
        int l = 0, r = n-1;
        bool found = 0;
        while(l <= r){
            int m = (l+r)/2;
            string x = s.substr(sa[m], min((int)t.length(), n - sa[m]));
            if(t == x){
                found = 1;
                break;
            }
            else if(t > x){
                l = m + 1;
            }
            else if (t < x){
                r = m - 1;
            }
        }
        if(found)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
