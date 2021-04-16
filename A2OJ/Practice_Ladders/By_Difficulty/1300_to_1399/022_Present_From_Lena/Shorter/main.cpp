#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/contest/118/problem/B

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < 2*n+1; i++){
        int j = i;
        if(j >= n)
            j = 2*n-i;
        for(int k = 0; k < n-j; k++)
            cout<<"  ";
        if(j)
            for(int k = 0; k <= j; k++)
                cout<<k<<" ";
        for(int k = j-1; k > 0; k--)
            cout<<k<<" ";
        cout<<"0\n";
    }
    return 0;
}
 