#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(auto &x: v)
        cin>>x;
    auto comp = [&](string a, string b){
        for(int i = 0; i < (int)min(a.length(), b.length()); i++){
            if(a[i] != b[i])
                return a[i] < b[i];
        }

        return a + b < b + a;   //This is actually the only part we need in the comparator to get AC
    };
    sort(v.begin(), v.end(), comp);
    for(string s: v)
        cout<<s;
}
