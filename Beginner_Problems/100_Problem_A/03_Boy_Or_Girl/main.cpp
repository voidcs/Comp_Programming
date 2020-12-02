#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    set<char> s;
    string str;
    cin>>str;
    for(int i = 0; i < str.length(); i++){
        s.insert(str[i]);
    }
    if(s.size() % 2)
        cout<<"IGNORE HIM!\n";
    else
        cout<<"CHAT WITH HER!\n";
    return 0;
}