#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int m = (2*n-2);
    vector<string> v(m);
    for(string &x: v)
        cin>>x;
    auto t = v;
    sort(v.begin(), v.end(), [](string a, string b){
        return a.length() > b.length();
    });
    bool ok = 1;
    string x = v[0][0] + v[1];
    vector<char> ans(m);
    set<int> used;
    for(int i = 0; i < m; i++){
        bool found = 0;
        if(!used.count(t[i].length())){
            for(int j = 1; j < x.length(); j++){
                string s = x.substr(0, j);
                if(t[i] == s){
                    found = 1;
                    ans[i] = 'P';
                }
            }
            for(int j = 1; j < x.length(); j++){
                string s = x.substr(j, n-j);
                if(t[i] == s){
                    found = 1;
                    ans[i] = 'S';
                }
            }
        }
        else{
            for(int j = 1; j < x.length(); j++){
                string s = x.substr(j, n-j);
                if(t[i] == s){
                    found = 1;
                    ans[i] = 'S';
                }
            }
            for(int j = 1; j < x.length(); j++){
                string s = x.substr(0, j);
                if(t[i] == s){
                    found = 1;
                    ans[i] = 'P';
                }
            }
        }
        if(!found)
            ok = 0;
        used.insert(t[i].length());
    }
    used.clear();
    if(!ok){
        x = v[1][0] + v[0];
        for(int i = 0; i < m; i++){
            bool found = 0;
            if(!used.count(t[i].length())){
                for(int j = 1; j < x.length(); j++){
                    string s = x.substr(0, j);
                    if(t[i] == s){
                        found = 1;
                        ans[i] = 'P';
                    }
                }
                for(int j = 1; j < x.length(); j++){
                    string s = x.substr(j, n-j);
                    if(t[i] == s){
                        found = 1;
                        ans[i] = 'S';
                    }
                }
            }
            else{
                for(int j = 1; j < x.length(); j++){
                    string s = x.substr(j, n-j);
                    if(t[i] == s){
                        found = 1;
                        ans[i] = 'S';
                    }
                }
                for(int j = 1; j < x.length(); j++){
                    string s = x.substr(0, j);
                    if(t[i] == s){
                        found = 1;
                        ans[i] = 'P';
                    }
                }
            }
            if(!found)
                ok = 0;
            used.insert(t[i].length());
        }
    }
    for(auto x: ans)
        cout<<x;
    return 0;
}