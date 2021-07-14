#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    int ans = 0, sum = 0;
    set<int> have;
    have.insert(0);
    for(int i = 0; i < n; i++){
        sum += s[i]-'0';
        sum %= 3;
        if(have.count(sum)){
            sum = 0;
            ans++;
            have.clear();
            have.insert(0);
        }
        else{
            have.insert(sum);
        }
    }
    cout<<ans<<endl;
    return 0;
}
