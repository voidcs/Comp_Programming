#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    int a, ta, b, tb;
    cin>>a>>ta>>b>>tb;
    string time;
    cin>>time;
    int hours = stoi(time.substr(0, 2));
    int mins = stoi(time.substr(3, 2));
    mins += hours*60;
    int ans = 0;
    int curr = 300;
    while(1){
        if(curr>1439 || curr>=mins+ta)
            break;
        if(curr+tb > mins)
            ans++;
        curr += b;
    }
    cout<<ans<<endl;
    return 0;
}
