#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--){
        string s;
        int n, k;
        cin>>n>>k>>s;
        int first;
        for(int i = 0; i < n; i++){
            if(s[i] == '*'){
                first = i;
                break;
            }
        }
        int ans = 1;
        int i = first;
        while(i < n){
            int j = min(n-1, i + k);
            while(i < j && s[j] == '.'){
                j--;
            }
            if(i == j)
                break;
            ans++;
            i = j;
        }
        cout<<ans<<endl;
    }
    return 0;
}