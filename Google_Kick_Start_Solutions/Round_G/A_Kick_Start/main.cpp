#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://codingcompetitions.withgoogle.com/kickstart/round/00000000001a0069

int main(){
    int c = 1;
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        ll n = str.length();
        ll count = 0, ans = 0;
        for(int i = 0; i < str.length(); i++){
            if(str.substr(i, 4) == "KICK")
                count++;
            if(str.substr(i, 5) == "START")
                ans += count;
        }
        cout<<"Case #"<<c++<<": "<<ans<<endl;
    }
    
    return 0;
}