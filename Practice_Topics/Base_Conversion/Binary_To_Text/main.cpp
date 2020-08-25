#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string str;
    while(cin>>str){
        int n = str.length();
        int letter = 0;
        for(int i = n-1; i >= 0; i--){
            letter += (str[i]-'0') << n-i-1;
        }
        cout<<static_cast<char>(letter);
    }
    return 0;
}