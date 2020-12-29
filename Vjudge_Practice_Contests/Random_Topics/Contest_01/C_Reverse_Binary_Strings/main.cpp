#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string str;
        cin>>n>>str;
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(str[i] == str[i-1]){
                int j = i + 1;
                while(j < n && str[j] != str[j-1])
                    j++;
                ans++;
                i = j;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}