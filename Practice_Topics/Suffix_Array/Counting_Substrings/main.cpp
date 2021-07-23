//https://codeforces.com/edu/course/2/lesson/2/3/practice/contest/269118/problem/B
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
        auto binary_search = [&](string str){
            int res = n;
            int l = 0, r = n-1;
            while(l <= r){
                int m = (l+r)/2;
                string x = s.substr(sa[m], min((int)t.length(), n - sa[m]));
                if(str <= x){
                    res = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            return res;
        };
        string upper = t;
        upper.back()++;
        //To find the count of string t, do upper_bound - lower_bound
        //To find the upper bound, do binary search on t with last letter increased by one
        cout<<max(0, binary_search(upper) - binary_search(t))<<endl;
    }
    return 0;
}
