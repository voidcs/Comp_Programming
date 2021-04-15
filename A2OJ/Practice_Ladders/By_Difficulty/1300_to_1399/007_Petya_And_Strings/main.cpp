#include <bits/stdc++.h>
using namespace std;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/112/A

int main(){
    string a, b;
    cin>>a>>b;
    for(int i = 0; i < a.length(); i++){
        a[i] = tolower(a[i]);
        b[i] = tolower(b[i]);
    }
    if(a < b)
        cout<<"-1\n";
    else if(a > b)
        cout<<"1\n";
    else
        cout<<"0\n";

    return 0;
}

