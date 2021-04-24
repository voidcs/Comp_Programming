#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/205/A

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    bool flag = 0;
    int ans = 1e9+5, index = -1;
    for(int i = 0; i < n; i++){
        if(v[i] == ans)
            flag = 1;
        if(v[i] < ans)
            flag = 0, ans = v[i], index = i+1;
    }
    if(flag)
        cout<<"Still Rozdil\n";
    else
        cout<<index<<endl;
    return 0;
}