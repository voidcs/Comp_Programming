//https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/B
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
    int x = 0, y = 0;
    vector<int> ans(m);
    while(x < n || y < m){
        if(y == m || (x < n && a[x] < b[y])){
            x++;
        }
        else if(x == n || (y < m && b[y] <= a[x])){
            ans[y] = x;
            y++;
        }
    }
    for(int x: ans)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
