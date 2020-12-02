#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    set<int> s;
    for(int i = 0; i < 4; i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    cout<<4-s.size()<<endl;
    return 0;
}