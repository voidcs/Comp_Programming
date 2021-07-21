#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    auto comp = [&](string a, string b){
        if(a.length() != b.length())
            return a.length() < b.length();
        return a < b;
    };
    sort(v.begin(), v.end(), comp);
    bool ok = 1;
    for(int i = 0; i < n-1; i++){
        if(v[i+1].find(v[i]) == std::string::npos){
            ok = 0;
        }
    }
    if(ok){
        cout<<"YES\n";
        for(auto x: v)
            cout<<x<<endl;
    }
    else
        cout<<"NO\n";
    return 0;
}
