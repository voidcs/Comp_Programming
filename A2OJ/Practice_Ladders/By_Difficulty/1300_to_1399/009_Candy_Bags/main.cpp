#include <bits/stdc++.h>
using namespace std;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/334/A

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= (n*n)/2; i++){
        cout<<i<<" "<<(n*n)-i+1<<" ";
        if(i%(n/2) == 0)
            cout<<"\n";
    }
    return 0;
}

