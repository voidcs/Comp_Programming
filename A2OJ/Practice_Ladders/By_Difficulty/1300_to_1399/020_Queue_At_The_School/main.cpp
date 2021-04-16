#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/266/B

int main(){
    int n, t;
    cin>>n>>t;
    string s;
    cin>>s;
    for(int i = 0; i < t; i++){
        for(int j = 0; j < n-1; j++){
            if(s[j] == 'B' && s[j+1] == 'G'){
                swap(s[j], s[j+1]);
                j++;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}
 