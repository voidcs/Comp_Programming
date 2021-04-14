#include <bits/stdc++.h>
using namespace std;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/61/A

int main(){
    string a, b;
    cin>>a>>b;
    for(int i = 0; i < a.length(); i++){
        int x = a[i]-'0', y = b[i]-'0';
        cout<<(x^y);
    }
    return 0;
}

