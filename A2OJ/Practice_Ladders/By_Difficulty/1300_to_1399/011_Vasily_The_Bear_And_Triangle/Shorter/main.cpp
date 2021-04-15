#include <bits/stdc++.h>
using namespace std;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/336/A

int main(){
    int x, y;
    cin>>x>>y;
    int d = abs(x) + abs(y);
    function<int(int)> sign = [&](int x){
        if(x > 0)
            return 1;
        else if (x < 0)
            return -1;
    };
    array<int, 2> a = {d * sign(x), 0};
    array<int, 2> b = {0, d * sign(y)};
    if(a > b)
        swap(a, b);
    cout<<a[0]<<" "<<a[1]<<" "<<b[0]<<" "<<b[1]<<endl;
    return 0;
}

