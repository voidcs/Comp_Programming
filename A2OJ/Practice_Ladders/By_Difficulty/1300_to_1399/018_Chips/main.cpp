#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/92/A

int main(){
    int n, k;
    cin>>n>>k;
    int i = 1;
    while(k >= i){
        k -= i;
        i = (i%n)+1;
    }
    cout<<k<<endl;
    
    return 0;
}
 