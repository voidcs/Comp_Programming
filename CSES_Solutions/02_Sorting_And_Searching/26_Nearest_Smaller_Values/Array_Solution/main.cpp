#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    ll a[n], b[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
        b[i] = i-1;
        while(b[i] != -1 && a[b[i]]>=a[i]){
            b[i] = b[b[i]];
        }
        cout<<b[i]+1<<" ";
    }
    return 0;
}