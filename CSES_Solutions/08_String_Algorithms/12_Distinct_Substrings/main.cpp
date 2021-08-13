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
    s += "#";
    int n = s.length();
    vector<int> sa(n), c(n);
    vector<pair<int, int>> v(n);
    //Linear sorting algorithm, suffix indices have small values
    auto count_sort = [&](){
        vector<int> cnt(n), sa_new(n);
        for(auto x: c)
            cnt[x]++;
        vector<int> pos(n);
        //Assign the first position for each bucket
        for(int i = 1; i < n; i++){
            pos[i] = pos[i-1] + cnt[i-1];
        }
        //Put in bucket and increment
        for(auto x: sa){
            int i = c[x];
            sa_new[pos[i]] = x;
            pos[i]++;
        }
        sa = sa_new;
    };
    //Sort the length 1 strings, we only do this once so an nlogn sort is ok
    for(int i = 0; i < n; i++)
        v[i] = {s[i] - '0', i};
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
        sa[i] = v[i].second;
    //Assign equivalence classes
    c[sa[0]] = 0;
    for(int i = 1; i < n; i++){
        c[sa[i]] = c[sa[i-1]] + !(v[i].first == v[i-1].first);
    }
    //Transition between lengths 2^k
    int k = 0;
    while(n > (1LL<<k)){
        for(int i = 0; i < n; i++){
            sa[i] = (sa[i] - (1<<k) + n) % n;
        }
        count_sort();
        vector<int> c_new(n);
        //Assign equivalence classes
        c_new[sa[0]] = 0;
        for(int i = 1; i < n; i++){
            pair<int, int> prev = {c[sa[i-1]], c[(sa[i-1] + (1<<k)) % n]};
            pair<int, int> now = {c[sa[i]], c[(sa[i] + (1<<k)) % n]};
            if(now == prev)
                c_new[sa[i]] = c_new[sa[i-1]];
            else
                c_new[sa[i]] = c_new[sa[i-1]] + 1;
        }
        c = c_new;
        k++;
    }
    k = 0;
    vector<int> lcp(n);
    for(int i = 0; i < n-1; i++){
        int pi = c[i];
        if(pi == 0)
            continue;
        int j = sa[pi-1];
        while(s[i+k] == s[j+k])
            k++;
        lcp[pi] = k;
        k = max(k-1, 0);
    }
//    for(int i = 0; i < n; i++)
//        cout<<lcp[i]<<" "<<sa[i]<<" "<<s.substr(sa[i])<<endl;
    ll ans = (((ll)n-1)*n)/2;
    for(int i = 1; i < n; i++){
        ans -= lcp[i];
    }
    cout<<ans<<endl;
    return 0;
}