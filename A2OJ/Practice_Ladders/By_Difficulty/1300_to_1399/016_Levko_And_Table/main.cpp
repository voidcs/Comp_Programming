#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/contest/361/problem/A

int main(){
    int n, k;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)
                cout<<k<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl; 
    }
    return 0;
}
 