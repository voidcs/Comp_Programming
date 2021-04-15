#include <bits/stdc++.h>
using namespace std;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/129/A
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    int sum = 0;
    sum = accumulate(v.begin(), v.end(), sum);
    int ans = 0;
    for(int x: v){
        if((sum-x) % 2 == 0)
            ans++;
    }
    cout<<ans<<endl;

    return 0;
}

