#include <bits/stdc++.h>
using namespace std;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/200/B

int main(){
    int n;
    cin>>n;
    long double ans = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        ans += x;
    }
    cout<<fixed<<setprecision(10)<<ans/n<<endl;
    return 0;
}

