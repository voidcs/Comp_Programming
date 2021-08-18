//https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int &x: a)
        cin>>x;
    for(int &x: b)
        cin>>x;
    ll ans = 0, j = 0;
    vector<int> equal(n);
    for(int i = 0; i < n; i++){
        if(i && a[i] == a[i-1]){
            equal[i] = equal[i-1];
        }
        else{
            while(j < m && b[j] < a[i])
                j++;
            while(j < m && b[j] == a[i]){
                equal[i]++, j++;
            }
        }
        ans += equal[i];
    }
    cout<<ans<<endl;
    return 0;
}
