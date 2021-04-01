#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int n, k;
        cin>>n>>k>>s;
        vector<int> v;
        int first, last;
        for(int i = 0; i < n; i++){
            if(s[i] == '*')
                v.push_back(i);
        }
        if(v.size() <= 2){
            cout<<v.size()<<endl;
            continue;
        }
        int ans = 2;
        first = v[0], last = v.back();
        v.pop_back();
        for(int i = 1; i < v.size(); i++){
            if(last - first <= k)
                continue;
            int j = i+1;
            while(j < v.size() && v[j] - first <= k)
                j++;
            ans++;
            i = j-1;
            first = v[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}