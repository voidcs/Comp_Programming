#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, k;
    cin>>n>>k;
    vector<long double> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    long double d = n-k+1;
    long double x = 0;
    long double y = 0;
    queue<long double> q;
    for(int i = 0; i < k; i++){
        y += v[i];
        q.push(v[i]);
    }
    x += y;
    for(int i = k; i < n; i++){
        y += v[i];
        q.push(v[i]);
        y -= q.front();
        q.pop();
        x += y;
    }
    cout<<fixed<<setprecision(10)<<x/d<<endl;
    
    return 0;
}