#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    if(n <= 10)
        cout<<"0\n";
    else if(n < 20)
        cout<<"4\n";
    else if(n == 20)
        cout<<"15\n";
    else if(n == 21)
        cout<<"4\n";
    else
        cout<<"0\n";
    return 0;
}