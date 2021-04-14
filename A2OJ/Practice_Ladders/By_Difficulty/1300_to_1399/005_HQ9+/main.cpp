#include <bits/stdc++.h>
using namespace std;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/133/A

int main(){
    string s;
    cin>>s;
    bool ans = 0;
    for(char c: s){
        if(c == 'H' || c == 'Q' || c == '9')
            ans = 1;
    }
    if(ans)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}

