#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    int n, x;
    cin>>n>>x;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    sort(v.begin(), v.end());
    int l = 0, r = n-1;
    int pairs = 0;
    while(l < r){
        if(v[l] + v[r] <= x)
            pairs++, l++, r--;
        else
            r--;
    }
    cout<<n - (2*pairs) + pairs<<"\n";
}
 