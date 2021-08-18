//https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/A
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
    vector<int> ans(n+m);
    int x = 0, y = 0, z = 0;
    while(x < n || y < m){
        if(y == m || (x < n && a[x] <= b[y])){
            ans[z++] = a[x++];
        }
        else if(x == n || (y < m && b[y] < a[x])){
            ans[z++] = b[y++];
        }
    }
    for(int x: ans)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
