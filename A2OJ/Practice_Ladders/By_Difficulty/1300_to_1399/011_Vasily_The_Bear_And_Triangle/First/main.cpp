#include <bits/stdc++.h>
using namespace std;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/336/A

int main(){
    int x, y;
    cin>>x>>y;
    int ans = abs(x) + abs(y);
    if(x > 0 && y > 0)
        cout<<"0 "<<ans<<" "<<ans<<" 0\n";
    else if(x < 0 && y > 0)
        cout<<-ans<<" 0 0 "<<ans<<endl;
    else if(x > 0 && y < 0)
        cout<<"0 "<<-ans<<" "<<ans<<" 0\n";
    else if(x < 0 && y < 0)
        cout<<-ans<<" 0 0 "<<-ans<<endl;
    return 0;
}

