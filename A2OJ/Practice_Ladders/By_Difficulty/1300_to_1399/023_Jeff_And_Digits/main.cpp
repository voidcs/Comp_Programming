#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/352/A

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    int fives = 0, zeros = 0;
    for(int &x: v){
        cin>>x;
        if(x == 0)
            zeros++;
        else
            fives++;
    }
    fives -= (fives % 9);
    if(zeros == 0)
        cout<<"-1\n";
    else if(fives < 9)
        cout<<"0\n";
    else{
        for(int i = 0; i < fives; i++)
            cout<<"5";
        for(int i = 0; i < zeros; i++)
            cout<<"0";
    }
    return 0;
}
 