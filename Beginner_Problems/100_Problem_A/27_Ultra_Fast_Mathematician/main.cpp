#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string a, b;
    cin>>a>>b;
    for(int i = 0; i < a.length(); i++){
        cout<<(a[i]-'0'^b[i]-'0');
    }
    
    return 0;
}