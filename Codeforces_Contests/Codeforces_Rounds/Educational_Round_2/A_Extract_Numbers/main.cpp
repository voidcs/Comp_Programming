#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    string s;
    cin>>s;
    s += ';';
    int n = s.length();
    string curr;
    string ans1 = "\"", ans2 = "\"";
    vector<string> a, b;
    for(int i = 0; i < n; i++){
        if(s[i] == ',' || s[i] == ';'){
            bool ok = 1;
            for(char c: curr){
                if(!isdigit(c))
                    ok = 0;
            }
            if(curr.size() > 1 && curr[0] == '0')
                ok = 0;
            if(curr.empty())
                ok = 0;
            if(ok)
                a.push_back(curr);
            else
                b.push_back(curr);
            curr.clear();
        }
        else
            curr += s[i];
    }
    for(int i = 0; i < (int)a.size(); i++){
        ans1 += a[i];
        if(i != (int)a.size() - 1)
            ans1 += ',';
    }
    for(int i = 0; i < (int)b.size(); i++){
        ans2 += b[i];
        if(i != (int)b.size() - 1)
            ans2 += ',';
    }
    ans1 += "\"";
    ans2 += "\"";
    if(a.size() == 0)
        cout<<"-\n";
    else
        cout<<ans1<<endl;
    if(b.size() == 0)
        cout<<"-\n";
    else
        cout<<ans2<<endl;
    return 0;
}
