#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n, q;
    cin>>n>>q;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    unordered_map<ll, ll> m;
    for(int i = 0; i < n; i++){
        m[a[i]] = i;
    }
    int index = -1, ans = 0;
    for(int i = 1; i <= n;){
        while(i <= n && m[i] > index){
            index = m[i];
            i++;
        }
        ans++, index = -1;
    }
    while(q--){
        ll i, j;
        cin>>i>>j;
        i--, j--;
        if(i == j){
            cout<<ans<<endl;
            continue;
        }
        ll x = a[i], y = a[j];
        if(x > y){
            swap(x, y);
            swap(i, j);
        }
        bool flag = 0;
        if(y-x == 1)
            flag = 1;
        if(x > 1){
            if(m[x] > m[x-1] && j <= m[x-1])
                ans++;
            if(m[x] < m[x-1] && j >= m[x-1])
                ans--;
        }
        if(x < n){
            if(m[x] > m[x+1] && j <= m[x+1])
                ans--;
            if(m[x] < m[x+1] && j >= m[x+1])
                ans++;
        }
        if(y > 1 && !flag){
            if(m[y] > m[y-1] && i <= m[y-1])
                ans++;
            if(m[y] < m[y-1] && i >= m[y-1])
                ans--;
        }
        if(y < n){
            if(m[y] < m[y+1] && i >= m[y+1])
                ans++;
            if(m[y] > m[y+1] && i <= m[y+1])
                ans--;
        }
        cout<<ans<<endl;
        swap(m[x], m[y]); 
        swap(a[i], a[j]);
    }
    return 0;
}