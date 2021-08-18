//https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/B
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> a(n), b(m), ans(m);
    for(int &x: a)
        cin>>xg
    for(int &x: b)
        cin>>x;
    int j = 0;
    for(int i = 0; i < m; i++){
        while(j < n && a[j] < b[i])
            j++;
        ans[i] = j;
    }
    for(int x: ans)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
