#include <bits/stdc++.h>
using namespace std;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/263/A

int main(){
    int a[5][5];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin>>a[i][j];
    int x, y;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(a[i][j]){
                y = i, x = j;
            }
        }
    }
    cout<<abs(y-2) + abs(x-2)<<endl;
    return 0;
}

