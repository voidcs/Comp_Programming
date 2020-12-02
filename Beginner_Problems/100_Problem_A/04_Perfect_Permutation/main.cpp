#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    int n;
    cin>>n;
    if(n%2)
        cout<<"-1\n";
    else{
        for(int i = 0; i < n; i++){
            if(i%2 == 0)
                cout<<i+2<<" ";
            else
                cout<<i<<" ";
        }
    }
    return 0;
}