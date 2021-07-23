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
    //First element in pair for half segment values
    //Second element for string index
    vector<pair<pair<int, int>, int>> v(n);

    //Assign values for k = 0;
    for(int i = 0; i < n; i++)
        v[i] = {{s[i] - '0', 0}, i};
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
        sa[i] = v[i].second;
    //Assign class values for different strings in increasing order
    c[sa[0]] = 0;
    for(int i = 1; i < n; i++){
        c[sa[i]] = c[sa[i-1]] + !(v[i].first == v[i-1].first);
    }
    
    //length k halfs for each string so k starts at 0
    int k = 0;
    while(n > (1LL<<k)){
        for(int i = 0; i < n; i++){
            //The first half starts at i, second half starts at (i + 2^k) % n because it loops around
            v[i] = {{c[i], c[(i + (1LL<<k)) % n]}, i};
        }

        //Sort and reassign order to vector
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++)
            sa[i] = v[i].second;

        //Assign class values for different strings in increasing order
        c[sa[0]] = 0;
        for(int i = 1; i < n; i++){
            c[sa[i]] = c[sa[i-1]] + !(v[i].first == v[i-1].first);
        }
        k++;
    }
    for(int i = 0; i < n; i++)
        cout<<sa[i]<<" ";
    cout<<endl;
    return 0;
}
