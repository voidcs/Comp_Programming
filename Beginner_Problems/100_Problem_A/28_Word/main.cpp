#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string str;
    cin>>str;
    ll upper = 0, lower = 0;
    ll n = str.length();
    for(int i = 0; i < n; i++){
        if(isupper(str[i]))
            upper++;
        else
            lower++;
    }
    if(upper > lower){
        for(int i = 0; i < n; i++)
            str[i] = toupper(str[i]);
    }
    else{
        for(int i = 0; i < n; i++)
            str[i] = tolower(str[i]);
    }
    cout<<str<<endl;
    
    return 0;
}