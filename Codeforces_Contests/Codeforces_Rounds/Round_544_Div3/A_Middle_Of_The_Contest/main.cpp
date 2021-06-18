#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    string a, b;
    cin>>a>>b;
    int x = 0, y = 0;
    x += stoi(a.substr(0, 2)) * 60;
    x += stoi(a.substr(3, 2));
    
    y += stoi(b.substr(0, 2)) * 60;
    y += stoi(b.substr(3, 2));
    int ans = (x+y)/2;
    int hours = ans/60, mins = ans%60;
    if(hours < 10)
        cout<<"0";
    cout<<hours<<":";
    if(mins < 10)
        cout<<"0";
    cout<<mins<<endl;
    return 0;
}