#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/problemset/problem/1367/B

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int even = 0, odd = 0, wrong = 0;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            if(a[i]%2 != i%2)
                wrong++;
            if(a[i]%2)
                odd++;
            else
                even++;
        }
        if(even == odd+1 || even==odd)
            cout<<wrong/2<<endl;
        else{
            cout<<"-1\n";
        }
        
    }
    return 0;
}