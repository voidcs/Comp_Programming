#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    string a, b;
    cin>>a>>b;
    int n = a.length(), m = b.length();
    int cnt = 0;
    for(int i = 0; i < min(n, m); i++){
        if(a[n-1-i] == b[m-1-i])
            cnt += 2;
        else
            break;
    }
    cout<<(n+m)-cnt<<endl;
    return 0;
}
