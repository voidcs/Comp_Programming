#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--){
        string a, b;
        cin>>a>>b;
        if(a.length() < b.length())
            swap(a, b);
        int n = a.length(), m = b.length();
        int ans = n+m;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                string x = a.substr(i, j-i+1);
                for(int k = 0; k < m; k++){
                    for(int l = k; l < m; l++){
                        string y = b.substr(k, l-k+1);
                        if(x == y)
                            ans = min(ans, (int)(n-x.length()) + (int)(m-y.length()));
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}