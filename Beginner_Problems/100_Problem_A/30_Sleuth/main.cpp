#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string str;
    getline(cin, str);
    int n = str.length();
    int index = n-1;
    while(!isalpha(str[index])){
        index--;
    }
    string vowel = "aeiouy";
    set<char> s;
    for(int i = 0; i < vowel.size(); i++)
        s.insert(vowel[i]);
    if(s.count(tolower(str[index])))
        cout<<"YES\n";
    else
        cout<<"NO\n";
    
    return 0;
}