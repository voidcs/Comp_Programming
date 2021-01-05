#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/problemset/problem/1398/B

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int n = str.length();
        vector<int> v;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            while(i < n && str[i] == '1'){
                cnt++;
                i++;
            }
            v.push_back(cnt);     
        }
        sort(v.rbegin(), v.rend());
        int ans = 0;
        for(int i = 0; i < v.size(); i++){
            if(i%2==0)
                ans += v[i];
        }
        cout<<ans<<endl;
            
    }
    return 0;
}